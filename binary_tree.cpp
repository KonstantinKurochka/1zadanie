#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

class BinTreeEl
{
public:

	BinTreeEl() {}

	BinTreeEl(int value)
	{
	    val = value;
        h = 1;
        left = NULL;
        right = NULL;
	}

	BinTreeEl* insert(int value)
    {
        BinTreeEl *node;
        if (!this)
        {
            node = new BinTreeEl;
            node->val = value;
            node->left = NULL;
            node->right = NULL;
            node->h = 1;
            return node;
        }
        if (value < this->val)
        {
            node = this->left->insert(value);
            if (!this->left)
                this->left = node;
            return node;
        }
        else
        {
            node = this->right->insert(value);
            if (!this->right)
                this->right = node;
            return node;
        }
    }

	void* remove (int value)
	{
        BinTreeEl** q, *z;

        z=this;
        q=&z;

        while(1)
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

            if(z->right == NULL)
                *q = z->left;
            else
            {
                BinTreeEl* y = z->right;
                if(y->left == NULL)
                {
                    y->left = z->left;
                    y->set_h();
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
                    x->set_h();
                    *q = x;
                }
            }
            this->balance();
    }

	bool exists(int value)
    {
        if (!this)
        {
            return false;
        }
        else
        {
            if (this->val == value)
                return true;
            else
            {
                if (this->val > value)
                {
                    BinTreeEl* a = this->left;
                    return a -> exists(value);
                }
                else
                {
                    BinTreeEl* b = this->right;
                    return b -> exists(value);
                }
            }
        }
    }

	void print_tree()
	{
        if (!this == 0)
            {
                this -> set_h();
                this -> left -> print_tree();
                cout << this -> val << " (" << this->h << "); ";
                this -> right -> print_tree ();
            }
    }

private:
    BinTreeEl* left_rotation()
    {
        if (!this)
            return NULL;
        BinTreeEl* pl = this -> left;
        this -> left = NULL;
        BinTreeEl* q = this -> right;
        int vp = this -> val, vq;
        if (q)
            vq = q -> val;
        else
            return this;
        BinTreeEl* qr = q -> right;
        q -> right = NULL;
        BinTreeEl* ql = q -> left;
        q -> left = NULL;
        this -> right = NULL;
        this -> val = vq; // полное очищение дерева

        this -> insert(vp);
        this -> left -> right = ql;
        this -> left -> left = pl;
        this -> right = qr; // сборка его обратно
        this->set_h();
        return this;
    }

	int bfactor()
	{
	    return this->right->set_h() - this->left->set_h();
	}

	BinTreeEl* right_rotation()
        {
        if (!this)
            return NULL;
        BinTreeEl* pr = this -> right;
        this -> right = NULL;
        BinTreeEl* q = this -> left;
        int vp = this -> val, vq;
        if (q)
            vq = q -> val;
        else
            return this;
        BinTreeEl* qr = q -> right;
        q -> right = NULL;
        BinTreeEl* ql = q -> left;
        q -> left = NULL;
        this -> left = NULL;
        this -> val = vq;

        this -> insert(vp);
        this -> right -> left = qr;
        this -> right -> right = pr;
        this -> left = ql;
        this -> set_h();
        return this;
    }

	BinTreeEl* balance()
	{
        if( this->bfactor()==2 )
        {
            if( this->right->bfactor() < 0 )
                this->right = this->right->right_rotation();
            BinTreeEl* a = this->left_rotation();
            return a;
        }
        if( this->bfactor()==-2 )
        {
            if( this->left->bfactor() > 0  )
                this->left = this->left->left_rotation();
            BinTreeEl* b = this->right_rotation();
            return b;
        }
        this->set_h();
        return this;
    }

    int set_h()
    {
        if (!this)
            return 0;
        this->h = max(this->left->set_h(), this->right->set_h()) + 1;
        return this->h;
    }

    int val, h;
	BinTreeEl* left;
	BinTreeEl* right;

};

int main()
{
	BinTreeEl *sample = new BinTreeEl();
    int i, n, num;
    cin >> n;
    cin >> num;
    *sample = BinTreeEl(num);

    for (i = 1; i < n; i++)
    {
        cin >> num;
        sample->insert(num);
    }

	cout << "Tree after creation:" << endl;
	sample->print_tree();

	cout << " " << endl;
	if (sample->exists(1))
		cout << "Search for value 1: found" << endl;

	if (!((sample)->exists(111)))
		cout << "Search for value 111: not found" << endl;

    sample->remove(7);
	cout << "Tree after deletion of the element: " << endl;
	sample->print_tree();

	return 0;
}
