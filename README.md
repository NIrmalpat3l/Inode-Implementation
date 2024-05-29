# Inode Implementation using C++ STL

This document describes the implementation of an inode system using C++ STL (Standard Template Library).

The code utilizes maps and linked lists to store and manage inodes.

## **Data Structures:**

- Inode: A structure representing an inode. It contains fields for:
- dataBlockID: The data block ID where the file data is stored.
- id: Unique identifier for the inode.
- name: Name of the file.
- size: Size of the file in bytes.
- permissions: Permissions associated with the file (e.g., read, write, execute).
- dateOfCreation: Date the file was created.
- next: Pointer to the next inode in the linked list (for storing multiple inodes within a data block).
- map<int, Inode*> dataBlockInfo: A map that stores a mapping between data block IDs and a pointer to the head of the linked list containing inodes within that block.
- map<int, int> is_repeated: A map to keep track of duplicate inode IDs (for ensuring unique IDs).

## **Class: LinkedList**

This class manages the linked list of inodes within a data block. It provides methods for:

- insertInode: Inserts a new inode into the linked list.
- displayInode: Displays all inodes in the system or within a specific data block. Can also filter by date of creation or permissions.
- updatePermissions: Updates the permissions for an inode with a specific ID.
- deleteInode: Deletes an inode with a specific ID.

## **Main Function:**

The main function provides a menu-driven interface for interacting with the inode system. Users can:

    1.Add a new inode.

    2.Find an inode by ID, date of creation, or permissions.

    3.Display all inodes.

    4.Update permissions for an inode.5.Delete an inode.

    6.Exit the program.

## **ScreenShot:**
**1.**
![SS-1](/Screenshot%202024-05-29%20180024.png)
***
**2.**
![SS-2](/Screenshot%202024-05-29%20180041.png)
***
**3.**
![SS-3](/Screenshot%202024-05-29%20180057.png)
***
**4.**
![SS-4](/Screenshot%202024-05-29%20180111.png)
***
**5.**
![SS-5](/Screenshot%202024-05-29%20180124.png)
***
**6.**
![SS-6](/Screenshot%202024-05-29%20180134.png)

## **Key Points:**

The code utilizes MAX_sizeOfDataBlock to define the maximum size of a data block.The curr_Datablock variable keeps track of the current data block being used.The flag variable indicates if the file size exceeds the data block size, triggering a new data block allocation.Error handling is included for invalid choices, duplicate inode IDs, and attempting to find/update/delete non-existent inodes.

**Note:**

This is a basic implementation and can be further extended to include features like data block management, actual file data storage, and more comprehensive permission handling.
