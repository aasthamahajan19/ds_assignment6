
#include <bits/stdc++.h>
using namespace std;

/* ----- CIRCULAR SINGLY LINKED LIST ----- */
struct CNode {
    int data;
    CNode* next;
    CNode(int x): data(x), next(nullptr) {}
};

class CircularList {
    CNode* last; // points to last node, last->next is head
public:
    CircularList(): last(nullptr) {}
    bool empty(){ return last==nullptr; }
    void insertFirst(int x){
        CNode* node = new CNode(x);
        if(!last){ node->next = node; last = node; return; }
        node->next = last->next;
        last->next = node;
    }
    void insertLast(int x){
        insertFirst(x);
        last = last->next;
    }
    bool insertAfter(int key, int x){
        if(!last) return false;
        CNode* cur = last->next;
        do{
            if(cur->data==key){
                CNode* node = new CNode(x);
                node->next = cur->next;
                cur->next = node;
                if(cur==last) last = node;
                return true;
            }
            cur = cur->next;
        }while(cur!=last->next);
        return false;
    }
    bool insertBefore(int key, int x){
        if(!last) return false;
        CNode* cur = last->next;
        CNode* prev = last;
        do{
            if(cur->data==key){
                CNode* node = new CNode(x);
                prev->next = node;
                node->next = cur;
                if(cur==last->next) { /* inserted before head */ }
                return true;
            }
            prev = cur; cur = cur->next;
        }while(cur!=last->next);
        return false;
    }
    bool deleteNode(int key){
        if(!last) return false;
        CNode* cur = last->next;
        CNode* prev = last;
        do{
            if(cur->data==key){
                if(cur==prev){ // single node
                    delete cur; last = nullptr; return true;
                }
                prev->next = cur->next;
                if(cur==last) last = prev;
                delete cur;
                return true;
            }
            prev = cur; cur = cur->next;
        }while(cur!=last->next);
        return false;
    }
    bool search(int key){
        if(!last) return false;
        CNode* cur = last->next;
        do{
            if(cur->data==key) return true;
            cur = cur->next;
        }while(cur!=last->next);
        return false;
    }
    void displayRepeatHead(){
        if(!last){ cout<<"Empty\n"; return; }
        CNode* head = last->next;
        CNode* cur = head;
        do{
            cout<<cur->data<<" ";
            cur = cur->next;
        }while(cur!=head);
        cout<<head->data; // repeat head at end
        cout<<"\n";
    }
    void display(){
        if(!last){ cout<<"Empty\n"; return; }
        CNode* head = last->next;
        CNode* cur = head;
        do{
            cout<<cur->data<<" ";
            cur = cur->next;
        }while(cur!=head);
        cout<<"\n";
    }
    int size(){
        if(!last) return 0;
        int cnt=0; CNode* cur=last->next;
        do{ cnt++; cur=cur->next; }while(cur!=last->next);
        return cnt;
    }
};

/* ----- DOUBLY LINKED LIST ----- */
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x): data(x), prev(nullptr), next(nullptr) {}
};

class DoublyList {
    DNode* head;
    DNode* tail;
public:
    DoublyList(): head(nullptr), tail(nullptr) {}
    bool empty(){ return head==nullptr; }
    void insertFirst(int x){
        DNode* node = new DNode(x);
        node->next = head;
        if(head) head->prev = node;
        head = node;
        if(!tail) tail = head;
    }
    void insertLast(int x){
        DNode* node = new DNode(x);
        node->prev = tail;
        if(tail) tail->next = node;
        tail = node;
        if(!head) head = tail;
    }
    bool insertAfter(int key, int x){
        DNode* cur = head;
        while(cur){
            if(cur->data==key){
                DNode* node = new DNode(x);
                node->next = cur->next;
                node->prev = cur;
                if(cur->next) cur->next->prev = node;
                cur->next = node;
                if(cur==tail) tail = node;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    bool insertBefore(int key, int x){
        DNode* cur = head;
        while(cur){
            if(cur->data==key){
                DNode* node = new DNode(x);
                node->next = cur;
                node->prev = cur->prev;
                if(cur->prev) cur->prev->next = node;
                cur->prev = node;
                if(cur==head) head = node;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    bool deleteNode(int key){
        DNode* cur = head;
        while(cur){
            if(cur->data==key){
                if(cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if(cur->next) cur->next->prev = cur->prev;
                else tail = cur->prev;
                delete cur; return true;
            }
            cur = cur->next;
        }
        return false;
    }
    bool search(int key){
        DNode* cur = head;
        while(cur){ if(cur->data==key) return true; cur = cur->next; }
        return false;
    }
    void display(){
        DNode* cur = head;
        while(cur){ cout<<cur->data<<" "; cur = cur->next; }
        cout<<"\n";
    }
    int size(){
        int cnt=0; DNode* cur=head;
        while(cur){ cnt++; cur=cur->next; }
        return cnt;
    }
};

/* ----- SIMPLE MENU ----- */
void cllMenu(CircularList &cll){
    while(true){
        cout<<"\nCircular List Menu:\n1. Insert First\n2. Insert Last\n3. Insert After\n4. Insert Before\n5. Delete Node\n6. Search\n7. Display (repeat head)\n8. Size\n9. Back\nChoose: ";
        int c; if(!(cin>>c)) return;
        if(c==1){ int x; cin>>x; cll.insertFirst(x); }
        else if(c==2){ int x; cin>>x; cll.insertLast(x); }
        else if(c==3){ int key,x; cin>>key>>x; cout<<(cll.insertAfter(key,x)?"Inserted\n":"Key not found\n"); }
        else if(c==4){ int key,x; cin>>key>>x; cout<<(cll.insertBefore(key,x)?"Inserted\n":"Key not found\n"); }
        else if(c==5){ int key; cin>>key; cout<<(cll.deleteNode(key)?"Deleted\n":"Key not found\n"); }
        else if(c==6){ int key; cin>>key; cout<<(cll.search(key)?"Found\n":"Not Found\n"); }
        else if(c==7){ cll.displayRepeatHead(); }
        else if(c==8){ cout<<cll.size()<<"\n"; }
        else break;
    }
}

void dllMenu(DoublyList &dll){
    while(true){
        cout<<"\nDoubly List Menu:\n1. Insert First\n2. Insert Last\n3. Insert After\n4. Insert Before\n5. Delete Node\n6. Search\n7. Display\n8. Size\n9. Back\nChoose: ";
        int c; if(!(cin>>c)) return;
        if(c==1){ int x; cin>>x; dll.insertFirst(x); }
        else if(c==2){ int x; cin>>x; dll.insertLast(x); }
        else if(c==3){ int key,x; cin>>key>>x; cout<<(dll.insertAfter(key,x)?"Inserted\n":"Key not found\n"); }
        else if(c==4){ int key,x; cin>>key>>x; cout<<(dll.insertBefore(key,x)?"Inserted\n":"Key not found\n"); }
        else if(c==5){ int key; cin>>key; cout<<(dll.deleteNode(key)?"Deleted\n":"Key not found\n"); }
        else if(c==6){ int key; cin>>key; cout<<(dll.search(key)?"Found\n":"Not Found\n"); }
        else if(c==7){ dll.display(); }
        else if(c==8){ cout<<dll.size()<<"\n"; }
        else break;
    }
}

int main(){
    CircularList cll; DoublyList dll;
    while(true){
        cout<<"\nMain Menu:\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nChoose: ";
        int c; if(!(cin>>c)) break;
        if(c==1) cllMenu(cll);
        else if(c==2) dllMenu(dll);
        else break;
    }
    return 0;
}
