#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int number;
     struct nodo *left, *right;
};

typedef struct nodo *ABB;


ABB creandoNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->number = x;
     nuevoNodo->left = NULL;
     nuevoNodo->right = NULL;

     return nuevoNodo;
}
void insertar(ABB &tree, int x)
{
     if(tree==NULL)
     {
           tree = creandoNodo(x);
     }
     else if(x < tree->number)
          insertar(tree->left, x);
     else if(x > tree->number)
          insertar(tree->right, x);
}

void preOrden(ABB tree)
{
     if(tree!=NULL)
     {
          cout << tree->number <<" ";
          preOrden(tree->left);
          preOrden(tree->right);
     }
}

void enOrden(ABB tree)
{
     if(tree!=NULL)
     {
          enOrden(tree->left);
          cout << tree->number << " ";
          enOrden(tree->right);
     }
}

void postOrden(ABB tree)
{
     if(tree!=NULL)
     {
          postOrden(tree->left);
          postOrden(tree->right);
          cout << tree->number << " ";
     }
}

void verArbol(ABB tree, int n)
{
     if(tree==NULL)
          return;
     verArbol(tree->right, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< tree->number <<endl;

     verArbol(tree->left, n+1);
}

int main()
{
    ABB arbol = NULL;

    int n;
    int x; 

    cout << "\n\t\t  ..[ Haciendo la busqueda del arbol]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Esto son la cantidades de lo nodos " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    cout << "\n Mostrando El arbol \n\n";
    verArbol( arbol, 0);

    cout << "\n Recorridos del arbol y su subnodos";

    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;

    system("pause");
    return 0;
}