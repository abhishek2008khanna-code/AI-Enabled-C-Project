# AI-Assisted Student Record and Result Management System

A console-based, menu-driven Student Record and Result Management System in **C** developed for the **Programming in C (PRC1001)** project-based assignment at **UPES (University of Petroleum and Energy Studies)**.

- **Student Name:** Abhishek Khanna
- **SAP ID:** 590032060
- **Course:** B.Tech CSE — Semester I (PRC1001)

## Current Status (Initial Setup)
- Defined the `Student` data structure storing SAP ID, Roll No., Name, Phone No., Email ID, Year, Current Semester, 8-semester SGPAs, and CGPA.
- Added dynamic `calculateCGPA()` logic to compute averages across completed semesters.
- Preloaded 5 initial student records across Years 1 to 4 for testing.
- Implemented the interactive console menu skeleton (`1`–`9`).

## Planned Features (Upcoming Commits)
- [ ] Student Record CRUD operations (Add, Search, Display All, Delete)
- [ ] Year-wise average CGPA analytics and sorting by SAP ID / Name
- [ ] AI-Assisted Academic Advisor based on CGPA performance tiers
- [ ] AI Usage Log and sample test input/output files

## How to Compile and Run
1. Compile the source file using `gcc`:
   ```bash
   gcc 590032060.c -o 590032060
