#include<iostream>


using namespace std;

struct Hyperlink{

int Number;

struct Hyperlink *nextH;

};


struct Node{

char Cell;
int Number;

struct Node* nextN;
struct Hyperlink *nextH;

};

struct Node *Head = NULL;
struct Node *Tail = NULL;




void Build(int Length, int Width);
void AddNode(int Number, char Cell, int L, int W);
void ScanMap(struct Node *N,bool V[]);
struct Node* SearchNode(int Number);


int main(){


   int result = 0;

   int width,length;
   cin >> length >> width;
   bool Visited[length*width+1];

   for(int i = 0 ; i<length*width+1 ; i++){

    Visited[i] = false;

   }

   Build(length, width);
   struct Node *Curr = Head;

   while(Curr!= NULL){
   if(Visited[Curr->Number] == false && Curr->Cell == '#'){

       ScanMap(Curr,Visited);
       result++;

       }

        Curr = Curr->nextN;

   }


   cout << endl << result << endl;






return 0;

}


void Build(int Length, int Width){



   char Cell;
   int Number = 0;

   for(int i = 0 ; i<Length*Width ; i++){


         cin >> Cell;
         AddNode(++Number, Cell, Length, Width);

       }

}



void AddNode(int Number, char Cell, int L, int W){


     int Trends[4];
     Trends[0] = Number-1;
     Trends[1] = Number+1;
     Trends[2] = Number-W;
     Trends[3] = Number+W;



     struct Node *N  =new struct Node;
     struct Hyperlink *H = NULL;

     N->Number = Number;
     N->Cell = Cell;
     N->nextN = NULL;
     N->nextH = NULL;

     if(Head == NULL){
        Head = N;
        Tail = N;
     }
     else{
            Tail->nextN = N;
            Tail = N;

        }

        for(int i = 0 ; i< 4 ; i++){

             if(Number%W == 0 && i == 1)
                    continue;
             if(Number%W == 1 && i == 0)
                    continue;

             if(0<Trends[i] && Trends[i]<(L*W+1)){

                H = new struct Hyperlink;
                H->Number = Trends[i];
                H->nextH = N->nextH ;
                N->nextH = H;

             }

        }


}



void ScanMap(struct Node *N,bool V[]){

       if(V[N->Number] == true)
        return;
       if(N->Cell == '*')
        return;

       V[N->Number] = true;

       struct Hyperlink *H = N->nextH;


       while(H != NULL){
          ScanMap(SearchNode(H->Number),V);

          H = H->nextH;
       }

}


struct Node* SearchNode(int Number){

   struct Node *Curr = Head;

   while(Curr != NULL && Curr->Number != Number)

         Curr = Curr->nextN;

       return Curr;

}
