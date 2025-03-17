# Project Overview

This repository contains several C programming projects, each solving different computational problems using a variety of techniques, including pointer arithmetic, encryption, and sequence validation.

## Project List

### 1. Dumpster Rental Cost Calculator
**File:** `project1_dumpster.c`  
**Description:**  
This program calculates the cost of renting a dumpster based on user selection and the number of rental days. It validates user inputs, assigns rental costs based on the selected dumpster type, and calculates the final charge based on predefined pricing rules.

---

### 2. Inflation Rate Calculator
**File:** `project2_inflation.c`  
**Description:**  
This program calculates the projected price of an item over the next five years, assuming a fixed annual inflation rate of 3%. The user inputs the current price, and the program outputs the estimated future prices.

---

### 3. Phone Number Letter to Digit Converter
**File:** `project2_phone.c`  
**Description:**  
This program converts the last seven letters of a phone number into their corresponding numeric values using a standard telephone keypad mapping (A-C → 2, D-F → 3, etc.). It processes the user input, identifies the relevant characters, and returns the converted phone number.

---

### 4. Encryption System
**File:** `project3_encryption.c`  
**Description:**  
This program encrypts a given numerical input by replacing each digit with its position in a user-specified encryption key. The user provides a list of digits to encrypt and an encryption key, and the program outputs the encoded result.

---

### 5. Teaching Assistant (TA) Assignment Checker
**File:** `project3_TA.c`  
**Description:**  
This program identifies an unassigned Teaching Assistant (TA) from a list. The user inputs the total number of TAs and the assigned ones, and the program finds and outputs the missing TA.

---

### 6. Alternating Sequence Validator
**File:** `project4_alternating.c`  
**Description:**  
This program checks whether a given sequence of numbers alternates between positive and negative values. It processes user input using pointer arithmetic and returns "yes" if the sequence alternates and "no" otherwise.

---

### 7. Student Tier Assignment
**File:** `project4_tier.c`  
**Description:**  
This program assigns students to different tiers based on how their points compare to predefined tier thresholds. It calculates the closest tier for each student and outputs the students categorized into Tier 1, Tier 2, or Tier 3.

---

### 8. Doubled Word Checker
**File:** `project5_doubled.c`  
**Description:**  
This program checks whether an input string consists of a word repeated twice in a row (e.g., "blingbling"). It uses pointer arithmetic to compare the first and second halves of the string.

---

### 9. Command-line Phone Number Converter
**File:** `project5_phone.c`  
**Description:**  
This program converts a phone number containing letters into its numeric equivalent using the standard telephone keypad mapping. It processes command-line arguments to perform the conversion and preserve non-alphabetic characters.

---

## Compilation and Execution

Each project can be compiled using `gcc`:

```sh
gcc -o <output_file> <source_file>.c
