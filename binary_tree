#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

class BinTreeEl
{
public:
	int val, h;
	BinTreeEl* left;
	BinTreeEl* right;
	BinTreeEl* insert(BinTreeEl* root, int value);
	void* remove(BinTreeEl* root, int value);
	bool exists(BinTreeEl* root, int value);
	void print_tree(BinTreeEl *tree);
	BinTreeEl();
	BinTreeEl(int value);
	BinTreeEl* balance(BinTreeEl* ver);
    int set_h(BinTreeEl* tree);
    void delete_tree (BinTreeEl* root);

private:
    BinTreeEl* left_rotation(BinTreeEl* p);
	int bfactor(BinTreeEl* ver);
	void fix_h(BinTreeEl* ver);
	BinTreeEl* right_rotation(BinTreeEl* p);
};


BinTreeEl::BinTreeEl() {}

BinTreeEl::BinTreeEl(int value)
{
	val = value;
	h = 1;
	left = NULL;
	right = NULL;
}

int BinTreeEl::set_h(BinTreeEl *tree)
{
    if (!tree)
        return 0;
    tree->h = max(set_h (tree->left), set_h (tree->right)) + 1;
    return tree->h;
}

int BinTreeEl::bfactor(BinTreeEl* p)
{
	return set_h(p->right)-set_h(p->left);
}

void BinTreeEl::fix_h(BinTreeEl* p)
{
	p->h = max (p->left->h, p->right->h) + 1;
}

void BinTreeEl::delete_tree (BinTreeEl* tree)
{
    if (!tree == 0)
        {
            delete_tree(tree->left);
            remove (tree, tree->val);
            delete_tree (tree->right);
        }
}

BinTreeEl* BinTreeEl::left_rotation(BinTreeEl* p)
{
    if (!p)
        return NULL;
    BinTreeEl* pl = p -> left;
    p -> left = NULL;
    BinTreeEl* q = p -> right;
    int vp = p -> val, vq;
    if (q)
        vq = q -> val;
    else
        return p;
    BinTreeEl* qr = q -> right;
    q -> right = NULL;
    BinTreeEl* ql = q -> left;
    q -> left = NULL;
    p -> right = NULL;
    p -> val = vq; // полное очищение дерева

    insert(p, vp);
    p -> left -> right = ql;
    p -> left -> left = pl;
    p -> right = qr; // сборка его обратно
    set_h(p);
    return p;
}

BinTreeEl* BinTreeEl::right_rotation(BinTreeEl* p)
{
    if (!p)
        return NULL;
    BinTreeEl* pr = p -> right;
    p -> right = NULL;
    BinTreeEl* q = p -> left;
    int vp = p -> val, vq;
    if (q)
        vq = q -> val;
    else
        return p;
    BinTreeEl* qr = q -> right;
    q -> right = NULL;
    BinTreeEl* ql = q -> left;
    q -> left = NULL;
    p -> left = NULL;
    p -> val = vq; // полное очищение дерева

    insert(p, vp);
    p -> right -> left = qr;
    p -> right -> right = pr;
    p -> left = ql; // сборка его обратно
    set_h(p);
    return p;
}

BinTreeEl* BinTreeEl::balance(BinTreeEl* p)
{
	fix_h(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = right_rotation(p->right);
		p = left_rotation(p);
		return p;
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = left_rotation(p->left);
		p = right_rotation(p);
		return p;
	}
	return p;
}

BinTreeEl* BinTreeEl::insert(BinTreeEl *tree, int value)
{
	BinTreeEl *node;
	if (!tree)
	{
		node = new BinTreeEl;
		node->val = value;
		node->left = NULL;
		node->right = NULL;
		node->h = 1;
		return node;
	}
	if (value < tree->val)
	{
		node = insert(tree->left, value);
		if (!tree->left)
			tree->left = node;
		return node;
	}
	else
	{
		node = insert(tree->right, value);
		if (!tree->right)
			tree->right = node;
		return node;
	}
    int a = set_h(tree);
}

void* BinTreeEl::remove(BinTreeEl* root, int value)
{
    BinTreeEl** q,*z;

    q=&root;
    z=root;
    while(1) // поиск
    {
        if(z == NULL) return 0;
        else if(value == z->val) break;
        else if(value > z->val)
        {
            q = &z->right;
            z = z->right;
        }
        else
        {
            q = &z->left;
            z = z->left;
        }
    }

    //удаление
    if(z->right == NULL)
        *q = z->left;
    else
    {
        BinTreeEl* y = z->right;
        if(y->left == NULL)
        {
            y->left = z->left;
            set_h(y);
            *q = y;
        }
        else
        {
            BinTreeEl* x = y->left;
            while(x->left != NULL)
            {
                y = x;
                x = y->left;
            }
            y->left = x->right;
            x->left = z->left;
            x->right = z->right;
            set_h(x);
            *q = x;
        }
    }
}

void BinTreeEl::print_tree(BinTreeEl *tree)
{
	if (!tree == 0)
        {
            print_tree(tree->left);
            cout << tree -> val << " (" << tree->h << "); ";
            print_tree (tree->right);
        }
}

bool BinTreeEl::exists(BinTreeEl* root, int value)
{
	if (!root)
	{
		return false;
	}
	else
	{
		if (root->val == value)
			return true;
		else
		{
			if (root->val > value)
			{
				root = root->left;
				return exists(root, value);
			}
			else
			{
				root = root->right;
				return exists(root, value);
			}
		}
	}
}

int main()
{
	BinTreeEl *sample = new BinTreeEl();
    int i, n, num;
    cin >> n;
	cin >> sample->val;

    for (i = 1; i < n; i++)
    {
        cin >> num;
        sample->insert(sample, num);
    }
    sample->set_h(sample);

	cout << "Tree after creation:" << endl;
	sample->print_tree(sample);

	cout << " " << endl;
	if (sample->exists(sample, 1))
		cout << "Search for value 1: found" << endl;

	if (!(sample)->exists(sample, 111))
		cout << "Search for value 111: not found" << endl;

    sample->remove(sample, 7);
	cout << "Tree after deletion of the element: " << endl;
	sample->print_tree(sample);

    sample->balance(sample);
    sample -> set_h(sample);
	cout << endl << "Tree after balancing: " << endl;
    sample->print_tree(sample);

	sample->delete_tree(sample);
	return 0;
}
