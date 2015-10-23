#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdio.h>

namespace CS225
{
struct ElementNode {
int data;
int pos;
struct ElementNode *next;
};
//forward declaration
class ElementProxy;
class SparseVector {

private:
ElementNode* pHead;
long dimension;


public:

 SparseVector() : pHead(NULL), dimension(0) {}
 ~SparseVector();
 SparseVector( const SparseVector& c);

const ElementProxy operator[](long pos);
int operator[](long pos) const;
const SparseVector& operator=(const SparseVector& v1);
ElementNode* getHead(void) const;
long getDimension() const;
void setHead(ElementNode* p);
void setDimension(long x);
int Get(long pos) const;
void Insert(int val, long pos);
void Delete(long pos);
SparseVector operator+(const SparseVector&  v1);
SparseVector operator*(const int s);
int operator*(const SparseVector& v1);


//STILL NEED TO DO THESE
SparseVector operator+=(const SparseVector& v);
SparseVector operator-=(const SparseVector& v);
SparseVector operator-(const SparseVector &v);






/*
Actual fn definitions

ElementProxy operator[](long pos)
int operator(long pos)
SparseVector operator+(SparseVector v)
SparseVector operator*(SparseVector v)
SparseVector operator*(int x)

*/



/*SparseVector operator+(SparseVector v);
int operator*(SparseVector v);
SparseVector operator*(int x);
*/

void PrintRaw ()const{ //used for grading
ElementNode* curr=pHead;
std::cout << "Raw vector: ";
while (curr) {
std::cout << "(" << curr->data << ", " << curr->pos << ")";
curr=curr->next;
}
std::cout << std::endl;
}
friend std::ostream& operator<<(std::ostream &out, const SparseVector &v);//implemented
//......

};










// uncomment when done with basic class functionality and ready to implement Proxy
class ElementProxy {
    private:
SparseVector &v;
long pos;



public:

ElementProxy(SparseVector& v, long pos): v(v), pos(pos){}

long getPos() const;
SparseVector getVector();
void setPos(long pos);
void setVector(SparseVector& v);


operator int() const
{
    return this->v.Get(pos);
}

ElementProxy operator=(int x)
{
    //printf("Entered proxy = op.\n");
    this->v.Insert(x, this->getPos());
   // printf("Insert successful, returning *this.\n");

    return *this;
}

 ElementProxy operator=(const int x) const
{
	 this->v.Insert(x, this->getPos());
	 return *this;
}


/*
void operator=(int x);
void operator=(ElementProxy x);
void operator+=(int x);
void operator+=(ElementProxy x);
void operator-=(ElementProxy x);
void operator-=(int x);
void operator=(ElementProxy* x);
void operator+=(ElementProxy* x);
void operator-=(ElementProxy* x);


ElementProxy operator=(int x);
ElementProxy operator=(ElementProxy x);
ElementProxy operator+=(int x);
ElementProxy operator+=(ElementProxy x);
ElementProxy operator-=(ElementProxy x);
ElementProxy operator-=(int x);
ElementProxy operator=(ElementProxy* x);
ElementProxy operator+=(ElementProxy* x);
ElementProxy operator-=(ElementProxy* x);
*/

// .......

};


}
#endif // VECTOR_H
