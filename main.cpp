#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Map.h"
#include <stack>
using namespace std;
// ��u�T�� 10227150 �յq��  ��u�T�� 10227135 ���@��   
  
void ch01(bool b) {
   fstream fp;
   fstream fp_out;
   bool save = false ;
   int ExitX = -1;  
   int ExitY = -1;
   string input = "", input2 = "" ;
   cout << "�п�J�ɦW : ",cin >> input, input += ".txt" ;
   fp.open(input.c_str(), ios::in);//�}���ɮ�
   input2 = input2.assign(input, 2, input.length()-2) ;
   input2 = "out" + input2 ; 
   fp_out.open(input2.c_str(), ios::out);
   fp >> ExitX ;
   fp >> ExitY ;  
   char MAZE[ExitX][ExitY] ;
   char MAZE2[ExitX][ExitY] ;
   ExitX -= 1, ExitY -= 1 ;  
   for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                fp >> MAZE[i][j],MAZE2[i][j] = MAZE[i][j] ;    
        } 
    fp.close();    
    if(b) {       
        int x=0, y=0;  
        plink path = NULL;  
        Map map;  
        cout << "[�C�L�X�g�c���|]" << endl;  
        for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << MAZE[i][j] << " ";  
            cout << endl;  
        }  
        // �}�l���g�c 
		path = map.push(x,y); 
        while( x<=ExitX && y<=ExitY){
		    //cout << "(" << x << "," << y <<")"  ;
            MAZE[x][y] = 'S';  
            if(x != 0 && NORTH=='E') {
			    if ( save ) path = map.push(x,y);   
                x-=1;  
                path = map.push(x,y);  
            } else if(x != ExitX && SOUTH=='E') { 
			    if ( save ) path = map.push(x,y);  
                x+=1;  
                path = map.push(x,y);  
            } else if(y != 0 && WEST=='E') {  
                if ( save ) path = map.push(x,y); 
                y-=1;  
                path = map.push(x,y);  
            } else if(y != ExitY &&EAST=='E') {
			    if ( save ) path = map.push(x,y);  
                y+=1;  
                path = map.push(x,y);  
            } else if(EAST == 'D' || WEST == 'D' ||SOUTH == 'D' || NORTH == 'D'){  
                cout << "\t>>> ���X�g�c!" << endl;  
                break;  
            } else if (x == -1) {
				MAZE[0][0] = 'B';  
                cout << "�S���X�f!!" << endl;  
                for(int i=0; i<ExitX+1; i++) {  
                  for(int j=0;j<ExitY+1; j++)  
                    cout << MAZE[i][j] << " ", fp_out << MAZE[i][j] << " ";  
                   cout << endl, fp_out << endl;  
                }
                fp_out.close();
                return ;
			} else { // ���즺�J�P 
			    save = true ; 
                MAZE[x][y] = 'S';  
                path = map.pop(&x, &y);  
            }
			//system("pause");  
        }
		MAZE[0][0] = 'B';  
        cout << "[�C�L�X�g�c���|]" << endl;  
        for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << MAZE[i][j] << " ", fp_out << MAZE[i][j] << " ";  
            cout << endl, fp_out << endl;  
        }
		for ( ;path != NULL ; path = path->next ) {
			MAZE2[path->x][path->y] = 'R' ;
		}
		cout << endl, fp_out << endl ; 
		for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << MAZE2[i][j] << " ", fp_out << MAZE2[i][j] << " ";  
            cout << endl, fp_out << endl;  
        }
		fp_out.close(); 
    }  
} 

struct loc {  
    int x,y;
};
typedef struct loc ploc;

bool rightnum( int x , int y , vector <ploc> candypath ) {
	for ( int i = 0 ; i < candypath.size() ; i++ ) {
		if ( x == candypath[i].x && y == candypath[i].y ) return false ;
	}
	return true ;
}

void ch02(bool b) {
   fstream fp;
   fstream fp_out;
   bool save = false ;
   int ExitX = -1;  
   int ExitY = -1;
   int Candy = -1, numCandy = 0;
   string input = "", input2 = "" ;
   cout << "�п�J�ɦW : ",cin >> input, input += ".txt" ;
   fp.open(input.c_str(), ios::in);//�}���ɮ�
   input2 = input2.assign(input, 2, input.length()-2) ;
   input2 = "out" + input2 ; 
   fp_out.open(input2.c_str(), ios::out);
   fp >> ExitX ;
   fp >> ExitY ;  
   fp >> Candy ;
   char MAZE[ExitX][ExitY] ;
   char MAZE2[ExitX][ExitY] ;
   ExitX -= 1, ExitY -= 1 ;  
   for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                fp >> MAZE[i][j],MAZE2[i][j] = MAZE[i][j] ;    
        } 
    fp.close();    
    if(b) {       
        int x=0, y=0;  
        plink path = NULL;
		vector <ploc> candypath ;  
        Map map;  
        cout << "[�C�L�X�g�c���|]" << endl;  
        for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << MAZE[i][j] << " ";  
            cout << endl;  
        }  
        // �}�l���g�c 
		path = map.push(x,y); 
        while( x<=ExitX && y<=ExitY){
		    //cout << "(" << x << "," << y <<")"  ;
            MAZE[x][y] = 'S';
            if (x == -1) {
				MAZE[0][0] = 'B';  
                cout <<  "�S��X�����_��!!"<< endl;  
                for(int i=0; i<ExitX+1; i++) {  
                  for(int j=0;j<ExitY+1; j++)  
                    cout << MAZE[i][j] << " ", fp_out << MAZE[i][j] << " ";  
                   cout << endl, fp_out << endl;  
                }
                fp_out.close();
                return ;
			} // �p�G�W�U���k����_�áA�N�ֿn�_�ӡA���Ҧ��_�ôN���X 
			if( y != ExitY && EAST == 'G' || y != 0 && WEST == 'G' || x != ExitX && SOUTH == 'G' || x != 0 && NORTH == 'G'){
              ploc newnode ;
			  bool pass = false ;	
			  if ( EAST == 'G' ) {
			    if ( rightnum( x, y + 1, candypath ) )  newnode.x = x, newnode.y = y + 1, candypath.push_back(newnode), numCandy++ ;
			  }
			  if ( WEST == 'G' ) {
			    if ( rightnum( x, y - 1, candypath ) )  newnode.x = x, newnode.y = y - 1, candypath.push_back(newnode), numCandy++ ;
			  }
			  if ( SOUTH == 'G' ) {
			    if ( rightnum( x + 1, y , candypath ) )  newnode.x = x + 1, newnode.y = y, candypath.push_back(newnode), numCandy++ ;
		      }
			  if ( NORTH == 'G' ) {
			    if ( rightnum( x - 1, y , candypath ) )  newnode.x = x - 1, newnode.y = y, candypath.push_back(newnode), numCandy++  ;
		      }

			  if ( numCandy == Candy ) {
                cout << "\t>>> ���X�g�c!" << endl;  
                break;
			  }
            } 

            if(x != 0 && NORTH=='E') {
			    if ( save ) path = map.push(x,y);   
                x-=1;  
                path = map.push(x,y);  
            } else if(x != ExitX && SOUTH=='E') { 
			    if ( save ) path = map.push(x,y);  
                x+=1;  
                path = map.push(x,y);  
            } else if(y != 0 && WEST=='E') {  
                if ( save ) path = map.push(x,y); 
                y-=1;  
                path = map.push(x,y);  
            } else if(y != ExitY &&EAST=='E') {
			    if ( save ) path = map.push(x,y);  
                y+=1;  
                path = map.push(x,y);  
            } else { // ���즺�J�P 
			    save = true ; 
                MAZE[x][y] = 'S';  
                path = map.pop(&x, &y);  
            }
			//system("pause");  
        }
		MAZE[0][0] = 'B';  
        cout << endl;  //�L�X���| 
        for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << MAZE[i][j] << " ", fp_out << MAZE[i][j] << " ";  
            cout << endl, fp_out << endl;  
        }

		fp_out.close(); 
    }  
}

struct Type_save
{
	int num;
	char type_use ;

};

struct Postion
{
	int _X, _Y;

	Postion(){}
	Postion(int X, int Y)
		: _X(X), _Y(Y){}
};

void	printMat(Type_save** maze, int ExitX, int ExitY)
{
	for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << maze[i][j].type_use << " ";  
            cout << endl;  
    }
}
int topx , topy ;
bool isCanGo(const int prePosValue,  //�p�G�S����A�]�S���L 
			 const int posX,
			 const int posY,
			 Type_save** maze)
{   
	if (   posX < 0 || posX > topx	
		|| posY < 0 || posY > topy		
		|| maze[posX][posY].type_use == 'O')
	{
		return false;
	}

	if (maze[posX][posY].num == 0)
		return true;
	else					
		return (prePosValue + 1) < maze[posX][posY].num;
}


int length(plink startNode){
    int num = 0;    
    while(startNode != NULL){
        num++;
        startNode = startNode->next;
    }
    return num;
}

Map map1;
Map map2;
plink path = NULL ;
plink path__ = NULL ;
//stack<Postion> path__;		
		
Postion offset[4];			

void shortestPath(
				  const Postion &start,
				  Type_save** & maze )   // �Q�λ��j�A���M�C�Ӹ��|�M��� 
{
	if ( maze[start._X][start._Y].type_use == 'G' )
	{   
		if (path__ == NULL || length(path) < length(path__ ) ){
			map2.reset() ;
			plink use = path ;
			while ( use != NULL ) {
				path__ = map2.push( use->x, use->y ) ;
				use = use->next ;
			}
		}	
		return;
	}
    maze[start._X][start._Y].type_use = 'S' ;
	for (int i = 0; i < 4; i++)
	{   
		int nNextPos_X = start._X + offset[i]._X;
		int nNextPos_Y = start._Y + offset[i]._Y;

		if (isCanGo(maze[start._X][start._Y].num, nNextPos_X, nNextPos_Y, maze))
		{
			maze[nNextPos_X][nNextPos_Y].num = maze[start._X][start._Y].num + 1;

			path = map1.push(nNextPos_X, nNextPos_Y);

			shortestPath( Postion(nNextPos_X, nNextPos_Y), maze);

			path = map1.pop(&nNextPos_X, &nNextPos_Y);
		}
	}
}

void ch03(){
	   fstream fp;
   fstream fp_out;
   bool save = false ;
   int ExitX = -1;  
   int ExitY = -1;

   string input = "", input2 = "" ;
   Postion start ;
   cout << "�п�J�ɦW : ",cin >> input, input += ".txt" ;
   fp.open(input.c_str(), ios::in);//�}���ɮ�
   input2 = input2.assign(input, 2, input.length()-2) ;
   input2 = "out" + input2 ;
   fp_out.open(input2.c_str(), ios::out);
   fp >> ExitX ;
   topx = ExitX - 1 ;
   fp >> ExitY ;
   topy = ExitY - 1;  
   fp >> start._X ;
   fp >> start._Y ;
   int xxx = start._X, yyy = start._Y;
   Type_save** MAZE ;
   Type_save** MAZE2 ;
   MAZE = new Type_save*[ExitX];
    for(int i = 0; i < ExitX; i++)
        MAZE[i] = new Type_save[ExitY];
   MAZE2 = new Type_save*[ExitX];
    for(int i = 0; i < ExitX; i++)
        MAZE2[i] = new Type_save[ExitY];     
   ExitX -= 1, ExitY -= 1 ;  
   for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++) { 
                fp >> MAZE[i][j].type_use,MAZE2[i][j] = MAZE[i][j] ;
				if ( MAZE[i][j].type_use == 'E' )  MAZE[i][j].num = 0 ;
				else if ( MAZE[i][j].type_use == 'O' )  MAZE[i][j].num = -1 ;
			} 
        }
	 
    fp.close();

	offset[0]._X = -1;	offset[0]._Y = 0;	//����������� 
	offset[1]._X = 1;	offset[1]._Y = 0;
	offset[2]._X = 0;	offset[2]._Y = -1;	
	offset[3]._X = 0;	offset[3]._Y = 1;
    stack<Postion> path ; 
    printMat(MAZE,ExitX,ExitY );
    cout << endl ;
	MAZE[start._X][start._Y].num = 1;		
	
	shortestPath( start, MAZE); // ��̵u���| 
    MAZE[xxx][yyy].type_use = 'B' ;   // �H�U�O�L�X�a�� 
    for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << MAZE[i][j].type_use << " ", fp_out << MAZE[i][j].type_use << " ";  
            cout << endl, fp_out << endl;  
    }
    cout << endl, fp_out << endl;
    while (path__ != NULL)
	{    if(  MAZE2[path__->x][path__->y].type_use != 'G' )MAZE2[path__->x][path__->y].type_use = 'R' ;
	     //cout << path__->x <<" "<< path__->y <<endl ;
	     path__ = path__->next ;
	}

    for(int i=0; i<ExitX+1; i++) {  
            for(int j=0;j<ExitY+1; j++)  
                cout << MAZE2[i][j].type_use << " ", fp_out << MAZE2[i][j].type_use << " ";  
            cout << endl, fp_out << endl;  
    }
    fp_out.close();
}

int main() {
	int command = -1 ;
   do { 
   cout << endl << "***** ���O���� ********************";
   cout << endl << "* 0. QUIT ����                    *";
   cout << endl << "* 1. ���Ȥ@                       *";
   cout << endl << "* 2. ���ȤG                       *";
   cout << endl << "* 3. ���ȤT                       *";
   cout << endl << "***********************************";
   cout << endl << "Input a command(0, 1, 2, 3): ";
   cin >> command; //����Ū���ާ@���O
   switch (command)
   { case 0: return 0 ;
     case 1: //
             ch01(true); 
             break;
     case 2: //
	         ch02(true); 
             break;
     case 3: ch03();
	        break ;
     default: cout << endl << "Command does not exist!" << endl;
   } // end switch
 } while (true); //���O'0': �����D�{��
	
	system("pause");
	return 0;
}

