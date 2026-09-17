# Challenge 09 - Patient Priority Queue

## Problem Statement

This project implements a Patient Priority Queue using the C programming language.

The system decides which patient should be treated next based on their priority number.

## Priority Rules

- Priority 1 = Emergency
- Priority 2 = Urgent
- Priority 3 = Routine

The patient with the lowest priority number is treated first.

If two patients have the same priority, the patient who arrived earlier is treated first.

## Patients Used for Testing

| Order Added | Patient | Priority |
|-------------|---------|----------|
| 1 | P1 | 3 |
| 2 | P2 | 1 |
| 3 | P3 | 2 |
| 4 | P4 | 1 |
| 5 | P5 | 3 |
| 6 | P6 | 2 |

## Expected Treatment Order

```text
P2 → P4 → P3 → P6 → P1 → P5
