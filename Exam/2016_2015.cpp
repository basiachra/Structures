//
// Created by Karolina on 03.05.2018.
//

//Dana jest następująca struktura opisująca drzewo:
//
//struct Tree{
//    Tree *parent;           // rodzic, lub NULL jeśli to korzen
//    Tree *left, *right;     // lewe i prawe dziecko
//    int w_left, w_right;    // wagi krawędzi do lewego i do prawego dziecka (dodatnie)
//};
//Proszę opisać (bez implementacji) możliwie jak najszybszy algorytm, który mając na wejściu 
//drzewo opisane przez strukturę Tree znajduje długość najdłuższej ścieżki między dwoma węzłami drzewa (prosta ścieżka to taka, która nie odwiedza żadnego węzła więcej niż raz).
//
//(Na potrzeby algorytmu mogą państwo uzupełnić strukturę Tree o dalsze pola.)

struct Tree{
	Tree *parent; //rodzic, lub NULL jeśli to korzeń
	Tree *left, *right; //lewe I prawe dziecko
	int w_left, w_right; //wagi krawędzi do lewego i do prawego dziecka (dodatnie)
	int longest_path, longest_path_to_root;	//najdluzsza sciezka w poddrzewie(lacznie z tym wezlem), najdluzsza sciezka do tego wezla
}

W kazdym wezle uzupelniam informacje o najdluzszej sciezce prowadzacej do tego wezla, oraz najdluzszej sciezce w drzewie zakorzenionym w tym wezle.

int longestPath(Tree* proot){
    updateTreeInformatins(proot);
    return proot->lpath;
}

void updateTreeInformatins(Tree* proot){
	if(!proot->left && !proot->right){
		proot->longest_path = proot->longest_path_to_root = 0;
		return;
	}
	int lpath, rpath;
	lpath = rpath = 0;
	if(proot->left){
		updateTreeInformation(proot->left)
		lpath = proot->wleft + proot->left->longest_path_to_root;
	}
	if(proot->right){
        updateTreeInformation(proot->right);
		rpath = proot->wright + proot->right->longest_path_to_root;
	}
	proot->longest_path_to_root = max(lpath, rpath);
	proot->longest_path = max(lpath + rpath, max(proot->left->longest_path, proot->right->longest_path));
}
