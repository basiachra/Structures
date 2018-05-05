#include<iostream>
using namespace std;

struct BSTnode{
    BSTnode * parent;
    BSTnode * left;
    BSTnode * right;
    int value;
};

BSTnode * findNode(BSTnode * root, int value){
    if(root == NULL) return NULL;
    if(root->value == value) return root;
    else if(value < root->value) return findNode(root->left,value);
    else return findNode(root->right,value);
}

void addNode(BSTnode *& root, int value){
    BSTnode * tmp = new BSTnode;
    tmp->value = value;
    tmp->left = tmp->right = tmp->parent = NULL;
    if(root == NULL) root = tmp;
    else{
        BSTnode * p = root; // element do przeszukiwania
        BSTnode * q = NULL; // previous dla parenta
        while(p != NULL){
            if(p->value < tmp->value){
                q = p;
                p = p->right;
            }
            else{
                q = p;
                p = p->left;
            }
        }
        if(q->value < value) q->right = tmp;
        else q->left = tmp;
        tmp->parent = q;
    }
}

int getMin(BSTnode * root){
    while(root->left != NULL) root = root->left;
    return root->value;
}

int getMax(BSTnode * root){
    while(root->right != NULL) root = root->right;
    return root->value;
}

BSTnode * succ(BSTnode * node){
    if(node->right != NULL){
        node = node->right;
        while(node->left != NULL) node = node->left;
        return node;
    }
    else{
        while(node->parent != NULL && node->parent->value < node->value) node = node->parent;
        return node;
    }
}

BSTnode * prev(BSTnode * node){
    if(node->left != NULL){
        node = node->left;
        while(node->right != NULL) node = node->right;
        return node;
    }
    else{
        while(node->parent != NULL && node->parent->value > node->value) node = node->parent;
        return node;
    }
}

int countInterval(BSTnode * T, int a, int b){
    if(!T) return 0;
    if(T->value == b && T->value == a) return 1;
    if(T->value <= b && T->value >= a) return 1 + countInterval(T->left,a,b) + countInterval(T->right,a,b);
    else if(T->value < a) return countInterval(T->right,a,b);
    else return countInterval(T->left,a,b);
}

int sumBST(BSTnode * T){
    if(!T) return 0;
    if(T->left == NULL && T->right == NULL) return T->value;
    else return T->value + sumBST(T->left) + sumBST(T->right);
}

int nodesAmount(BSTnode * T){
    if(!T) return 0;
    if(T->left == NULL && T->right == NULL) return 1;
    else return 1 + nodesAmount(T->left) + nodesAmount(T->right);
}

double avarge(BSTnode * T){ return sumBST(T) / nodesAmount(T);}

double avarge2(BSTnode * T, double & count, double & sum){
	if(T == NULL) return 0;
	avarge2(T->left,count,sum);
	avarge2(T->right,count,sum);
	if(T != NULL){
		sum += T->value;
		count++;
	}
	if(T->parent == NULL) return sum / count;
}

BSTnode * getNode(BSTnode *& root, BSTnode * z){
    BSTnode * y, * x;
    if(z->left == NULL || z->right == NULL) y = z;
    else y = succ(z);
    if(y->left != NULL) x = y->left;
    else x = y->right;
    if(x != NULL) x->parent = y->parent;
    if(y->parent == NULL) root = x;
    else if(y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    if(y != z) z->value = y->value;
    return y;
}

void deleteTree(BSTnode * root){
    if(root != NULL){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void printBST(BSTnode * root){
    if(root != NULL){
        if(root->left) printBST(root->left);
        cout << root->value << " ";
        if(root->right) printBST(root->right);
    }
}

int main(){
    BSTnode * tree = NULL;
    addNode(tree,15);
    addNode(tree,11);
    addNode(tree,20);
    addNode(tree,7);
    addNode(tree,12);
    addNode(tree,19);
    addNode(tree,30);
    addNode(tree,8);
    BSTnode * finded = findNode(tree,20);
    BSTnode * removed = getNode(tree,finded);
    double c = 0, s = 0;
    cout << "ilosc z przedzialu [a,b] to " << countInterval(tree,5,12) << endl;
    cout << "suma wartosci wezlow w drzewie to " << sumBST(tree) << endl;
    cout << "ilosc wezlow w drzewie to " << nodesAmount(tree) << endl;
    cout << "srednia wartosc wezla to " << avarge2(tree,c,s) << endl;
    printBST(tree);
}
