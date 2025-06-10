import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout, BatchNormalization
from tensorflow.keras.regularizers import l2
from tensorflow.keras.callbacks import EarlyStopping
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import seaborn as sns
import random

np.random.seed(42)
random.seed(42)

# Generate synthetic DHT sensor data
def generate_data(samples=20000):
    X, y = [], []
    for _ in range(samples):
        r = random.random()
        if r < 0.2:
            temp = random.uniform(20, 28)
            hum = random.uniform(40, 60)
            label = 0
        elif r < 0.4:
            temp = random.uniform(29, 40)
            hum = random.uniform(61, 90)
            label = 1
        elif r < 0.6:
            temp = random.uniform(5, 17)
            hum = random.uniform(10, 39)
            label = 2
        elif r < 0.8:
            temp = random.uniform(29, 40)
            hum = random.uniform(10, 39)
            label = 3
        else:
            temp = random.uniform(5, 17)
            hum = random.uniform(61, 90)
            label = 4

        temp += np.random.normal(0, 0.5)
        hum += np.random.normal(0, 1.0)

        if random.random() < 0.05:
            temp = random.uniform(17, 20)
            hum = random.uniform(39, 41)
            label = random.choice([0, 2, 4])

        X.append([temp, hum])
        y.append(label)

    return np.array(X), np.array(y)

# Prepare data
X, y = generate_data(20000)
X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, stratify=y, random_state=42)

# Build model
model = Sequential([
    Dense(64, activation='relu', input_shape=(2,), kernel_regularizer=l2(0.001)),
    BatchNormalization(),
    Dropout(0.2),
    Dense(64, activation='relu', kernel_regularizer=l2(0.001)),
    BatchNormalization(),
    Dropout(0.2),
    Dense(32, activation='relu', kernel_regularizer=l2(0.001)),
    BatchNormalization(),
    Dense(5, activation='softmax')
])

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

early_stop = EarlyStopping(monitor='val_loss', patience=10, restore_best_weights=True)

model.fit(X_train, y_train, epochs=50, batch_size=32,
          validation_data=(X_val, y_val),
          callbacks=[early_stop], verbose=1)

# Save model
model.save("dht_classifier.h5")

# Evaluate
y_pred = np.argmax(model.predict(X_val), axis=1)
print("\nClassification Report:")
print(classification_report(y_val, y_pred, digits=4))

cm = confusion_matrix(y_val, y_pred)
labels = ['Normal', 'HotHumid', 'ColdDry', 'HotDry', 'ColdHumid']

plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=labels, yticklabels=labels)
plt.title("Confusion Matrix")
plt.xlabel("Predicted")
plt.ylabel("Actual")
plt.tight_layout()
plt.show()

# Convert to TFLite
converter = tf.lite.TFLiteConverter.from_keras_model(model)
converter.optimizations = [tf.lite.Optimize.DEFAULT]
tflite_model = converter.convert()

with open("dht_classifier.tflite", "wb") as f:
    f.write(tflite_model)

print("✅ Model converted to TFLite.")