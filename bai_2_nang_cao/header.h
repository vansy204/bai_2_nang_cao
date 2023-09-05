#pragma once

#include <iostream>
#include<fstream>
#include <string>
#include <string.h>
using namespace std;
struct xe {
    string ma;
    string ten;
    int phankhoi;
    float gia;
};
struct node {
    xe bike;
    node* next;
};
node* makenode(xe bike);
void push_back(node*& head, xe bike);
xe* doc_1_xe(ifstream& filein, xe* bike);
void doc_danh_sach_xe(node*& head);
bool check_empty(node* head);
void xuat_1_xe(node* head);
void duyet(node* head);
void tim_xe_co_ten_x(node* head, string x);
void in_cac_xe_co_gia_cao(node* head);
int dem_so_xe_tren_100_phan_khoi(node* head);
node* last_node(node* head);
node* partition_1(node* first, node* last);
void quick_sort_1(node* first, node* last);
node* partition_2(node* first, node* last);
void quick_sort_2(node* first, node* last);
int size(node* head);
node* find_mid(node* start, node* last);
node* binary_search(node* head, int x);
void ghi_1_xe_vao_file(ofstream& fileout, node* head);
bool checkFileWithFstream(string path);
void ghi_danh_sach_da_sap_xep_vao_file(node* head,string x);
void menu();
