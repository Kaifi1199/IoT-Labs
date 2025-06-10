# Lab 12: TensorFlow Lite Micro – Model Integration and Kernel Testing

## Objective

This lab is designed to provide hands-on experience with **TensorFlow Lite for Microcontrollers (TFLM)**, focusing on testing various machine learning model operators and evaluating their performance in constrained embedded environments.

## Contents Overview

* `.tflite` model files for various operators (e.g., `strided_slice`, `transpose_conv`, `sub`).
* Corresponding `.csv` files for:

  * Input data
  * Expected (golden) outputs
* C++ source files implementing and testing TFLM kernels:

  * `add.cc`, `conv.cc`, `depthwise_conv.cc`, `activations.cc`, etc.
  * Associated test files: `*_test.cc`

## Purpose of the Lab

* Learn how to test and verify the correctness of model execution on microcontrollers.
* Explore how TensorFlow Lite Micro integrates various kernel operations.
* Understand the structure of model files and how test automation is done with CSV data.

## Technologies Used

* **Framework**: TensorFlow Lite for Microcontrollers (TFLM)
* **Languages**: C++, Python (for preprocessing, not included here)
* **Data Files**: `.csv` files for inputs and expected outputs
* **Models**: Quantized `.tflite` models for unit testing

## How to Use

1. Clone the TensorFlow repository and navigate to the `lite/micro` directory.
2. Integrate the test models and CSV files into the appropriate test folders.
3. Use Makefiles or build scripts (e.g., `Makefile.inc`) to compile and run the tests.
4. Compare inference results with golden values to verify correctness.

## Learning Outcomes

* Familiarity with low-level machine learning model testing on embedded systems.
* Understanding of operator implementation in TensorFlow Lite Micro.
* How to write, run, and verify unit tests for ML operators using real input/output datasets.

## Applications

* Embedded AI and Edge ML development.
* Verification pipelines for on-device inference.
* Performance benchmarking for ML operators on microcontrollers.

## Author

This lab is part of an advanced embedded ML curriculum focusing on real-world deployment and testing of AI models on constrained devices.

---
