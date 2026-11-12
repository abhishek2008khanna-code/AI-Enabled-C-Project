# AI-Assisted Student Record and Result Management System

A console-based, menu-driven Student Record and Result Management System written in **C** for the **Programming in C (PRC1001)** project-based assignment at **UPES (University of Petroleum and Energy Studies)**.

- **Student Name:** Abhishek Khanna
- **SAP ID:** 590032060
- **Program:** B.Tech CSE — Semester I (PRC1001)

## Features
- **Preloaded Student Database:** Initializes with 5 sample student records across Years 1 to 4 for immediate testing.
- **Add Student Record:** Stores SAP ID, Roll No., Name, Phone No., Email ID, Year (1st–4th), Current Semester, and SGPAs across up to 8 semesters with duplicate SAP ID validation.
- **Search & Display:** Instant lookup of individual student records by SAP ID.
- **Automatic CGPA Calculation:** Computes each student's CGPA dynamically by averaging completed semester SGPAs (`sgpa > 0.0`).
- **Year-Wise Analytics:** Calculates and displays the average CGPA for each academic year (1st to 4th Year).
- **Non-Destructive Sorting Views:** Displays all records sorted in increasing order of **SAP ID** or alphabetically by **Name** using a temporary copy of the array.
- **Delete Record:** Removes an existing student record cleanly by SAP ID.
- **AI-Assisted Academic Advisor:** Evaluates a student's CGPA using rule-based decision logic (`if-else`) across four performance categories (*Excellent Performance*, *Good Performance*, *Needs Improvement*, and *Requires Immediate Attention*) and identifies their lowest-scoring semester.

## Repository Structure
```text
student-record-ai-c/
├── 590032060.c            # Complete C source code
├── README.md              # Project documentation
├── AI_USAGE_LOG.md        # Log of AI prompts, outputs, and manual verifications
└── tests/
    ├── sample_input.txt   # Sample menu inputs for testing
    └── sample_output.txt  # Captured console output showing 4 CGPA advisor cases
