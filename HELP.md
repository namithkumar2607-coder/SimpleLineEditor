# Simple Line Editor - Help

## Description

This is a simple command-line line editor written in C.
It allows the user to insert, delete and display lines
of a document.

## Commands

### 1. Insert Line

Used to insert a new line at a specified line number.

Syntax:
insert <line number>

Example:
insert 2

The user then enters the text for the new line.

### 2. Delete Line

Used to delete a line from the document.

Syntax:
delete <line number>

Example:
delete 2

The specified line is deleted and the remaining lines
are shifted up.

### 3. Display Document

Used to display all lines with their line numbers.

Example:
display

### 4. Quit

Used to exit the line editor.

Example:
quit

## Error Handling

The editor displays an error message when an invalid
line number is entered.

If there are no lines in the document, it displays:
"Document is empty."