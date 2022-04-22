#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int number;
     struct nodo *left, *right;
};

typedef struct nodo *NODO;

NODO NewNodo(int x)
{
     NODO New = new(struct nodo);
     New->number = x;
     New->left = NULL;
     New->right = NULL;

     return New;
}
void Insertando(NODO &tree, int x)
{
     if(tree==NULL)
     {
           tree = NewNodo(x);
     }
     else if(x < tree->number)
          Insertando(tree->left, x);
     else if(x > tree->number)
          Insertando(tree->right, x);
}



void preOrden(NODO tree)
{
     if(tree!=NULL)
     {
          cout << tree->number <<" ";
          preOrden(tree->left);
          preOrden(tree->right);
     }
}

void enOrden(NODO tree)
{
     if(tree!=NULL)
     {
          enOrden(tree->left);
          cout << tree->number << " ";
          enOrden(tree->right);
     }
}

void postOrden(NODO tree)
{
     if(tree!=NULL)
     {
          postOrden(tree->left);
          postOrden(tree->right);
          cout << tree->number << " ";
     }
}

void Check(NODO tree, int n)
{
     if(tree==NULL)
          return;
     Check(tree->right, n+1);

     for(int i=0; i<n; i++)
         cout<<" ";

     cout<< tree->number <<endl;

     Check(tree->left, n+1);
}

int main()
{
    NODO tree = NULL;

    int n;
    int x; 

    cout << " NUMERO DE NODOS - ARBOL:    ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " CANTIDAD DE NODOS...... " << i+1 << ":    ";
        cin >> x;
        Insertando( tree, x);
    }

    cout << "\n IMPRIMIENDO........ \n\n";
    Check( tree, 0);

    cout << "\n RECORRIDOS EN 3...2...1....";


    cout << "\n En orden   :  ";             enOrden(tree);
    cout << "\n Pre Orden  :  ";             preOrden(tree);
    cout << "\n Post Orden :  ";             postOrden(tree);




    system("pause");
    return 0;
}