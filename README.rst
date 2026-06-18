==================
 Coding Challenge
==================

Write a program in both C++ and Python that fulfills the following requirements.

Functionality Requirements
--------------------------

* Reads the provided ``test.data`` file.
* Parses each line of the file into an object.

  + Fields are comma separated and you can assume that fields do not contain
    commas.
  + Handles commented out lines in data ('#' at beginning of line).
  + Ignores empty lines.

* Stores the object into a lookup table keyed by the name field.
* Prints to stdout the data from the lookup table sorted by key.
* Prints a list of names that like peas.
* Asks user to enter a name to lookup, then prints the object if found or an
  error message if not found.

C++ Requirements
----------------

* Compile with C++14 at a minimum.
* Can only use Standard Template Library.

Python Requirements
-------------------

* Use Python-3.
* Can only use Python Standard Library modules.
