#include "header.h"

node* makenode(xe bike) {
    node* newnode = new node();
    newnode->bike = bike;
    newnode->next = NULL;
    return newnode;
}
void push_back(node*& head, xe bike) {
    node* newnode = makenode(bike);
    node* temp = head;
    if (head == NULL) {
        head = newnode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}
xe* doc_1_xe(ifstream& filein, xe* bike) {
    getline(filein, bike->ma, ',');
    getline(filein, bike->ten, ',');
    filein >> bike->phankhoi;
    filein.seekg(1, 1);
    filein >> bike->gia;
    return bike;
}
void doc_danh_sach_xe(node*& head) {
    ifstream filein;
    filein.open("xe.txt", ios_base::in);
    if (!filein.is_open()) {
        cerr << "fail to open file" << endl;
        return;
    }
    while (!filein.eof()) {
        xe* bike = new xe();
        bike = doc_1_xe(filein, bike);
        push_back(head, *bike);
    }
    filein.close();
}
bool check_empty(node* head) {
    return(head == NULL) ? true : false;
}
void xuat_1_xe(node* head) {
    cout << head->bike.ma << " | " << head->bike.ten << " | " << head->bike.phankhoi << " | " << head->bike.gia << endl;
}
void duyet(node* head) {
    if (check_empty(head)) {
        cout << "danh sach trong" << endl;
        return;
    }
    else {
        while (head != NULL) {
            xuat_1_xe(head);
            head = head->next;
        }
    }

}
void tim_xe_co_ten_x(node* head, string x) {
    if (check_empty(head)) cout << "danh sach trong" << endl;
    else {
        int check = -1;
        while (head != NULL) {
            if (head->bike.ten == x) {

                xuat_1_xe(head);
                check = 1;
            }
            head = head->next;
        }
        if (check == -1) cout << "khong co xe ban can tim" << endl;
    }
}
void in_cac_xe_co_gia_cao(node* head) {
    int check = -1;
    if (check_empty(head)) cout << "danh sach trong" << endl;
    else {

        while (head != NULL) {
            if (head->bike.gia >= 150) {
                xuat_1_xe(head);
                check = 1;
            }
            head = head->next;
        }
    }
    if (check == -1) cout << "khong co xe nao tren 150 trieu" << endl;
}
int dem_so_xe_tren_100_phan_khoi(node* head) {
    int count = 0;
    while (head != NULL) {
        if (head->bike.phankhoi >= 100) {
            count++;
        }
        head = head->next;
    }
    return count;
}
node* last_node(node* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}
node* partition_1(node* first, node* last) {
    node* pivot = first;
    node* front = first;
    xe temp;
    while (front != NULL && front != last) {
        if (front->bike.gia < last->bike.gia) {
            pivot = first;
            temp = first->bike;
            first->bike = front->bike;
            front->bike = temp;
            first = first->next;
        }
        front = front->next;
    }
    temp = first->bike;
    first->bike = last->bike;
    last->bike = temp;
    return pivot;
}
void quick_sort_1(node* first, node* last) {
    if (first == last) return;
    node* pivot = partition_1(first, last);
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort_1(pivot->next, last);
    }
    if (pivot != NULL && first != pivot) {
        quick_sort_1(first, pivot);
    }
}
node* partition_2(node* first, node* last) {
    node* pivot = first;
    node* front = first;
    xe temp;
    while (front != NULL && front != last) {
        if (front->bike.phankhoi > last->bike.phankhoi) {
            pivot = first;
            temp = first->bike;
            first->bike = front->bike;
            front->bike = temp;
            first = first->next;
        }
        front = front->next;
    }
    temp = first->bike;
    first->bike = last->bike;
    last->bike = temp;
    return pivot;
}
void quick_sort_2(node* first, node* last) {
    if (first == last) return;
    node* pivot = partition_2(first, last);
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort_2(pivot->next, last);
    }
    if (pivot != NULL && first != pivot) {
        quick_sort_2(first, pivot);
    }
}
int size(node* head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}
node* find_mid(node* start, node* last) {
    if (start == NULL) {
        return NULL;
    }
    node* slow = start;
    node* fast = start->next;
    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}
node* binary_search(node* head, int x) {
    node* start = head;
    node* last = NULL;
    do {
        node* mid = find_mid(head, last);
        if (mid == NULL)return NULL;
        if (mid->bike.phankhoi == x)return mid;
        else if (mid->bike.phankhoi < x) start = mid->next;
        else last = mid;
    } while (last == NULL || last != start);
    return NULL;
}
void ghi_1_xe_vao_file(ofstream& fileout, node* head) {
    fileout << head->bike.ma << ", " << head->bike.ten << ", " << head->bike.phankhoi << ", " << head->bike.gia << endl;
}

bool checkFileWithFstream(string path) {
    ifstream isf(path);
    return isf.good();
}
void ghi_danh_sach_da_sap_xep_vao_file(node* head, string x) {
    string location;
    ofstream fileout;
    location = "E:\\CTDL & GT\\bai_2_nang_cao\\bai_2_nang_cao\\" + x;
    if (checkFileWithFstream(location)) {
        
        cout << "file da ton tai" << endl;
        while (true) {
            cout << "ban muon ghi de hay tiep tuc ghi: " << endl;
            cout << "1. ghi de" << endl;
            cout << "2. tiep tuc ghi vao cuoi" << endl;
            int luachon;
            cout << "lua chon cua ban la: ";
            cin >> luachon;
            if (luachon == 1) {
                
                fileout.open(x, ios_base::out);
                break;
            }
            else if (luachon == 2) {
                
                fileout.open(x, ios_base::app);
                break;
            }  
        }
        if (!fileout.is_open()) {
            cerr << "fail to open file" << endl;
            return;
        }
        while (head != NULL) {
            ghi_1_xe_vao_file(fileout, head);
            head = head->next;
        }
        fileout.close();
    }
    else {
        fileout.open(x, ios_base::out);
        if (!fileout.is_open()) {
            cerr << "fail to open file" << endl;
            return;
        } 
        while (head != NULL) {
            ghi_1_xe_vao_file(fileout, head);
            head = head->next;
        }
        fileout.close();
    }
}

void menu() {
    node* head = NULL;
    doc_danh_sach_xe(head);
    while (true) {

        cout << "\n============================================================" << endl;
        cout << "= 1. Tim mot xe co ten X" << endl;
        cout << "= 2. In ra danh sach cac xe co gia tren 150 trieu" << endl;
        cout << "= 3. Dem so xe co gia tren 100 phan khoi" << endl;
        cout << "= 4. Sap xep danh sach tang dan theo gia" << endl;
        cout << "= 5. Sap xep giam dan theo phan khoi " << endl;
        cout << "= 6. tim kiem xe theo phan khoi bang binary" << endl;
        cout << "= 7. ghi danh sach da sap xep vao file" << endl;
        cout << "= 0. Thoat" << endl;
        cout << "============================================================" << endl;
        duyet(head);
        cout << "============================================================" << endl;
        int luachon;
        cout << "Nhap lua chon cua ban: ";
        cin >> luachon;
        if (luachon == 1) {

            string x;
            cout << "Nhap ten xe ban muon tim: ";
            cin.ignore();
            getline(cin, x);
            cout << "xe ban can tim la: ";
            tim_xe_co_ten_x(head, x);
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (luachon == 2) {

            cout << "cac xe co gia tren 150 trieu la: ";
            in_cac_xe_co_gia_cao(head);
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (luachon == 3) {

            if (head == NULL) cout << "danh sach trong" << endl;

            else {

                cout << "danh sach co " << dem_so_xe_tren_100_phan_khoi(head) << " xe tren 100 phan khoi" << endl;
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (luachon == 4) {
            quick_sort_1(head, last_node(head));
            cout << "danh sach da sap xep tang dan theo gia la: " << endl;
            duyet(head);
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (luachon == 5) {
            quick_sort_2(head, last_node(head));
            cout << "danh sach da sap xep giam dan theo phan khoi la: " << endl;
            duyet(head);
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (luachon == 6) {
            quick_sort_2(head, last_node(head));
            int x;
            cout << "Nhap phan khoi ban muon tim: ";
            cin >> x;
            node* temp = binary_search(head, x);
            if (temp == NULL) cout << "khong co xe co phan khoi ban can tim" << endl;
            else {
                while (head != NULL) {
                    if (head->bike.phankhoi == temp->bike.phankhoi) {
                        xuat_1_xe(head);
                    }
                    head = head->next;
                }
            }
            system("pause");
            system("cls");
        }
        else if (luachon == 7) {
            string x;
            cout << "nhap ten file: ";
            cin.ignore();
            getline(cin, x);
            quick_sort_2(head, last_node(head));
            ghi_danh_sach_da_sap_xep_vao_file(head,x);
            cout << "ghi thanh cong" << endl;
            system("pause");
            system("cls");
        }
        else {
            break;
        }
    }
}