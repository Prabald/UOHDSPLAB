# Address Book
 Due date: Saturday, 10 December 2022, 11:59 PM
 Maximum number of files: 1
Type of work:  Individual work

### Create student address management application in C (Address Book) using C Random access file processing. Usually a record in a student address book contains the following fields:
### Roll Number, Name, Phone Number and Email

The application should contain the following options:
- Adding new student record (Append at the end of the file)
- Modifying student record (based on roll number)
- Search of student address based on name
- Deleting student record (If the Roll Number is “#DELETE#” then the record should be treated as deleted).

When the program loads initially all the records marked
“#DELETE#” should permanently removed from the file by creating a new student.dat
file which contains only active records.
The data stored in the file (file name: student.dat) should be permanent until the user deletes himself using the delete option of the application.
Note: Go through the C file opening modes and use the proper mode to open the address data file in order to make sure the data is never lost.

The following function can be used to rename a file in C:

int rename(const char *old_filename, const char *new_filename)