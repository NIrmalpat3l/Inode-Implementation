#include <bits/stdc++.h> 
 
using namespace std; 
 
const int MAX_sizeOfDataBlock = 10; 
bool flag = 0; 
int sizeOfDataBlock = 0; 
int curr_Datablock = 1; 
int cnt = 1; 
 
struct Inode { 
    int dataBlockID; 
    int id;
    string name; 
    int size; 
    string permissions; 
    string dateOfCreation; 
    Inode* next; 
}; 
 
map<int, Inode*> dataBlockInfo; 
map<int, int> is_repeated; 
 
class LinkedList { 
public: 
    LinkedList() : temp(nullptr), headOfList(nullptr) {} 
 
    void insertInode(int id, const string& name, int size, const string& permissions, 
const string& dateOfCreation) { 
        ++is_repeated[id]; 
        Inode* newInode = new Inode; 
        sizeOfDataBlock += size; 
        if (sizeOfDataBlock > MAX_sizeOfDataBlock) { 
            sizeOfDataBlock = size; 
            ++curr_Datablock; 
            temp = nullptr; 
            flag = 1; 
            cout << "\nThis file exceeds the size of the data-block,\nso this file will be saved in the next data-block.\n"; 
        } 
        newInode->dataBlockID = curr_Datablock; 
        newInode->id = id; 
        newInode->name = name; 
        newInode->size = size; 
        newInode->permissions = permissions; 
        newInode->dateOfCreation = dateOfCreation; 
 
        if (temp == nullptr) { 
            temp = newInode; 
            headOfList = newInode; 
            dataBlockInfo[curr_Datablock] = temp; 
        } else { 
            temp->next = newInode; 
            temp = newInode; 
        } 
 
        newInode->next = nullptr; 
    } 
 
    void displayInode() { 
        for (auto node : dataBlockInfo) { 
            cout << "DataBlock : " << cnt << endl << endl; 
            Inode* current = node.second; 
            while (current != nullptr) { 
                cout << "\tID: " << current->id << ", Name: " << current->name << ", Size: " << current->size << ", Permissions: " << current->permissions  << ", Date: " << current->dateOfCreation << endl; 
                current = current->next; 
            } 
            cnt++; 
            cout << endl; 
        } 
        cnt = 1; 
    } 
 
    void displayInode(int inodeID) { 
        bool found = false; 
        for (auto node : dataBlockInfo) { 
            Inode* current = node.second; 
            while (current != nullptr) { 
                if (current->id == inodeID) { 
                    cout << "Data_Block: " << current->dataBlockID << ", ID: " << current->id << ", Name: " << current->name 
                         << ", Size: " << current->size << ", Permissions: " << current->permissions << ", Date: "  << current->dateOfCreation << endl; 
                    found = true; 
                } 
                current = current->next; 
            } 
        } 
        if (!found) { 
            cout << "Inode not found with ID " << inodeID << endl; 
        } 
    } 
 
    void displayInode(const string& dateOfCreation) { 
        cout << "Inodes created on " << dateOfCreation << ":\n"; 
        bool found = false; 
        for (auto node : dataBlockInfo) { 
            Inode* current = node.second; 
            while (current != nullptr) { 
                if (current->dateOfCreation == dateOfCreation) { 
                    cout << "Data_Block: " << current->dataBlockID << ", ID: " << current->id << ", Name: " << current->name << ", Size: " << current->size << ", Permissions: " << current->permissions << ", Date: "  
                         << current->dateOfCreation << endl; 
                    found = true; 
                } 
                current = current->next; 
            } 
        } 
        if (!found) { 
            cout << "No Inodes found with the creation date " << dateOfCreation << endl; 
        } 
    } 
 
    void displayInodeByPermissions(const string& permissions) { 
        cout << "Inodes with permissions " << permissions << ":\n"; 
        bool found = false; 
        for (auto node : dataBlockInfo) { 
            Inode* current = node.second; 
            while (current != nullptr) { 
                if (current->permissions == permissions) { 
                    cout << "Data_Block: " << current->dataBlockID << ", ID: " << current->id << ", Name: " << current->name << ", Size: " << current->size << ", Permissions: " << current->permissions << ", Date: "  << current->dateOfCreation << endl; 
                    found = true; 
                } 
                current = current->next; 
            } 
        } 
        if (!found) { 
            cout << "No Inodes found with permissions " << permissions << endl; 
        } 
    } 
 
    void updatePermissions(int inodeID) { 
        for (auto node : dataBlockInfo) { 
            Inode* current = node.second; 
            while (current != nullptr) { 
                if (current->id == inodeID) { 
                    cout << "Enter new permissions for inode " << inodeID << ": "; 
                    cin >> current->permissions; 
                    cout << "Permissions updated." << endl; 
                    return; 
                } 
                current = current->next; 
            } 
        } 
        cout << "Inode not found with ID " << inodeID << endl; 
    } 
 
    void deleteInode(int inodeID) { 
        for (auto& node : dataBlockInfo) { 
            Inode* current = node.second; 
            Inode* previous = nullptr; 
 
            while (current != nullptr) { 
                if (current->id == inodeID) { 
                    if (previous != nullptr) { 
                        previous->next = current->next; 
                    } else { 
                        node.second = current->next; 
                    } 
                    delete current; 
                    cout << "Inode with ID " << inodeID << " has been deleted." << endl; 
                    return; 
                } 
                previous = current; 
                current = current->next; 
            } 
        } 
        cout << "Inode not found with ID " << inodeID << endl; 
    } 
 
private: 
    Inode* temp; 
    Inode* headOfList; 
}; 
 
int main() { 
    LinkedList inodeList; 
    int id, size; 
    string name, permissions, dateOfCreation; 
    char choice; 
 
    while (true) { 
        cout << "\nInode Operations Menu:\n"; 
        cout << "1. Add Inode\n"; 
        cout << "2. Find Inode\n"; 
        cout << "3. Display Inodes\n"; 
        cout << "4. Update Permissions\n"; 
        cout << "5. Delete Inode\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case '1': 
                cout << "Enter ID for the new inode: "; 
                cin >> id; 
                if (is_repeated[id] > 0) { 
                    cout << "Enter Unique ID for the current inode: "; 
                    cin >> id; 
                } 
                cout << "Enter name for the new inode: "; 
                cin >> name; 
                cout << "Enter size for the new inode: "; 
                cin >> size; 
                cout << "Enter permissions for the new inode: "; 
                cin >> permissions; 
                cout << "Enter date(DD/MM/YY) of creation of file for the new inode: "; 
                cin >> dateOfCreation; 
                inodeList.insertInode(id, name, size, permissions, dateOfCreation); 
                break; 
            case '2': 
                cout << "How would you like to find the inode?\n"; 
                cout << "1. By ID\n"; 
                cout << "2. By Date\n"; 
                cout << "3. By Permissions\n"; 
                cout << "Enter your choice: "; 
                cin >> choice; 
                if (choice == '1') { 
                    cout << "Enter the ID to find an inode: "; 
                    cin >> id; 
                    cout << "\nInode Details:\n"; 
                    inodeList.displayInode(id); 
                } else if (choice == '2') { 
                    cout << "Enter the date(DD/MM/YY) to find inodes created on that day: "; 
                    cin >> dateOfCreation; 
                    inodeList.displayInode(dateOfCreation); 
                } else if (choice == '3') { 
                    cout << "Enter the permissions to find inodes with those permissions: "; 
                    cin >> permissions; 
                    inodeList.displayInodeByPermissions(permissions); 
                } else { 
                    cout << "Invalid choice. Please try again." << endl; 
                } 
                break; 
            case '3': 
                cout << "\nInode List:\n\n"; 
                inodeList.displayInode(); 
                break; 
            case '4': 
                cout << "Enter the ID of the inode to update permissions: "; 
                cin >> id; 
                inodeList.updatePermissions(id); 
                break; 
            case '5': 
                cout << "Enter the ID of the inode to delete: "; 
                cin >> id; 
                inodeList.deleteInode(id); 
                break; 
            case '6': 
                cout << "Exiting the program." << endl; 
                return 0; 
            default: 
                cout << "Invalid choice. Please try again." << endl; 
                break; 
} 
} 
return 0; 
} 