#include "vector.h"
#include <stdio.h>
#include <stdlib.h>



namespace CS225
{
/*
   SparseVector operator*(int t, SparseVector v)
    {
        return v*t;
    }

SparseVector::SparseVector()
{
    pHead=NULL;
    dimension = 0;
}
*/
SparseVector::~SparseVector()
{
	printf("Calling destructor\n");
    if(pHead != NULL)
  {

    ElementNode * current = pHead;
    ElementNode * next = (*pHead).next;

    while(current != NULL)
    {
        delete(current);
        current = next;
        if(next != NULL)
        {next = next->next;}
    }
}

}



SparseVector::SparseVector( const SparseVector& v)
{
	printf("Calling copy ctor\n");

    ElementNode * start = new ElementNode();
    if(v.getHead() != NULL)
   {

    start->pos = v.getHead()->pos;
    start->data = v.getHead()->data;
   start->next = v.getHead()->next;
   }
    while(start)
    {
		if (start->data != 0)
		{
			this->Insert(start->data, start->pos);
		}
        start = start->next;

    }
	

}

    /* this is the only place where dimension is used */
std::ostream& operator<<(std::ostream &out, const SparseVector &v) {
	int i,last_pos=-1;
	ElementNode* p_e=v.getHead();
	while (p_e) {
		for (i=last_pos+1;i<p_e->pos;++i) out << " " << "0";
		out << " " << p_e->data;
		last_pos=p_e->pos;
		p_e = p_e->next;
	}
	for (i=last_pos+1;i<v.getDimension();++i) out << " " << "0";

	return out;
}

void SparseVector::Insert(int val, long pos)
{

//printf("Attempting to get / set dimension\n");
if (pos>=this->getDimension())
{this->setDimension(pos+1); }// automatically set dimension (it effects operator<< only)


/*
    printf("Creating node to insert\n");


    printf("Breaks at 1\n");*/
    ElementNode * nodeToInsert = new ElementNode();


        if(nodeToInsert == NULL)
    {
        /*printf("ERROR:  Insufficient memory.\n");*/
        delete(nodeToInsert);
        return;
    }
/*
printf("Breaks at 2\n");


   /* printf("Assigning values\n");*/


    nodeToInsert->data = val;
    nodeToInsert->pos = pos;
    nodeToInsert->next = NULL;


/*printf("Breaks at 3\n");
   /* printf("Creating current node\n");*/
  // printf("Attempting to create 'current' node\n");
    ElementNode * current = this->getHead();




  //  printf("'current' node created successfully\n");
/*printf("Breaks at 3.5\n");
*/
if(current == NULL)
{
  //  printf("enters if statement 1\n");
    if(val!=0)
   {
     //  printf("breaks at 1\n");
       this->setHead(nodeToInsert);
       return;
   }
   /* printf("Error checking:  current==NULL, so assigned nodeToInsert to pHead.  Should have 3 0's here:  %i, %i, %i\n", nodeToInsert->data - (pHead)->data, nodeToInsert->pos - (pHead)->pos, nodeToInsert->next - (pHead)->next);
    */
    else
{
  //  printf("breaks at 2\n");
 delete(nodeToInsert);
 return;

}

}
//printf("after if statement 1\n");
//printf("current, pHead values:  %s, %s", current, this->getHead());
/*printf("Breaks at 4\n");
*/
ElementNode * next = this->getHead()->next;

if(next == NULL)
{
    /* If input pos < head pos, this node becomes the new head   DOUBLE CHECK DIS  */
    if(pos < (this->getHead())->pos)
    {/*printf("Breaks at 5\n");


       */
       //printf("breaks at 3\n");
        nodeToInsert->next = (this->getHead());
        this->getHead()->next = NULL;
        this->setHead(nodeToInsert);

        return;
    }
    /*  If input pos > head pos, this node comes AFTER the head node, and the head stays the same  */
    else if(pos > this->getHead()->pos)
    {

        /*printf("Breaks at 6\n");*/
       // printf("breaks at 4\n");
        this->getHead()->next = nodeToInsert;



        return;
    }

    else if(val==0)
    {//printf("breaks at 5\n");
        /*
        printf("Breaks at 7\n");
       */ delete(this->getHead());

            delete(nodeToInsert);
        return;
    }

    else
    {
        printf("breaks at 6\n");
        /*printf("Breaks at 8\n");
        */
        (this->getHead())->data = val;

        delete(nodeToInsert);
        return;
    }
}



do
{

    /* Input pos < starting node pos, make nodeToInsert the new head and point it to the old one  */
    if(pos < (this->getHead())->pos)
    {
       // printf("breaks at 7\n");
       /* printf("Breaks at 9\n");*/
        nodeToInsert->next = (this->getHead());
        this->setHead(nodeToInsert);



        return;

    }
    /* Input pos == starting node pos, delete & update head if val = 0, update data otherwise */
    else if(pos == (this->getHead())->pos)
    {
        if(val==0)
        {
           /* printf("Breaks at 10\n");*/
         //   printf("breaks at 8\n");
            nodeToInsert = (this->getHead())->next;
            delete(this->getHead());
            this->setHead(nodeToInsert);


            return;
        }
        else
        {  // printf("breaks at 9\n");
            /*printf("Breaks at 11\n");*/
            (this->getHead())->data = val;
            delete(nodeToInsert);
            return;
        }
    }

    /* Input pos fits between some two nodes, put it in between those two nodes  */
   else if(next != NULL && current->pos < pos && next->pos > pos)
    {
       // printf("breaks at 10\n");
        /*printf("Breaks at 12\n");*/
        current->next = nodeToInsert;
        nodeToInsert->next = next;


        return;
    }

    else if(next!= NULL && next->pos == pos)
    {

        /*printf("Breaks at 13\n");
        */
        if(val==0)
        {
           // printf("breaks at 11\n");
         current->next = next->next;
         delete(next);

            delete(nodeToInsert);
         return;
        }

        else
        {  // printf("breaks at 12");
            next->data = val;

            delete(nodeToInsert);
            return;
        }
    }

/* Reached the end of the list and input position STILL greater than last node's position, just append nodeToInsert to the end of the list */
    else if(current->pos < pos && next == NULL)
    {
      //  printf("breaks at 13\n");
        /*printf("Breaks at 14\n");*/
        current->next = nodeToInsert;


        return;
    }

/*  */
    else
    {

      //  printf("breaks at 14\n");
        /*printf("Breaks at 15\n");*/
        current = next;
        next = next->next;
    }
}while(current != NULL);

}



int SparseVector::Get(long pos) const
{
 const ElementNode * n = this->getHead();


    do{
    if(n->pos == pos)
    {
        return n->data;
    }

    else
    {
       /* printf("Current position & data check:  %i, %i\n", n->pos, n->data);*/

        if(n->pos > pos)
        {
            n=NULL;
        }
        else
      {
          n=n->next;
      }
       /* printf("Position of n->next (also shows n->next exists):  %i", n->pos);

      /*  if(n->next != NULL)
        {n=n->next;}
        else
        {return 0;}
    */}
    }while(n!=NULL);

	return 0;
}

int SparseVector::operator[](long pos) const
{
    return this->Get(pos);
}



void SparseVector::Delete(long pos)
{



    ElementNode * prev = this->getHead();
    ElementNode * current = (prev)->next;

    if(prev->pos == pos)
    {
        delete(prev);
        this->setHead(current);
    }


    do
    {

        if(current->pos == pos)
        {
            /* If we're deleting the head node, delete *p_e and point the head to the next node */

            prev->next = current->next;
            delete(current);

        }

        else if(current->pos > pos)
        {
            current = NULL;
            /* No position corresponding to input, nothing to delete. */
        }

        else
        {

            prev = current;
            if(current != NULL)
            {current=current->next;}
        }

    }
    while(current!=NULL);


}

ElementNode* SparseVector::getHead() const
{
    return pHead;
}



long SparseVector::getDimension() const
{

return dimension;


}

void SparseVector::setHead(ElementNode* p)
{
    pHead = p;
}

void SparseVector::setDimension(long x)
{
    dimension=x;
}

long ElementProxy::getPos() const
{
    return this->pos;
}

SparseVector ElementProxy::getVector()
{
    return this->v;
}

void ElementProxy::setPos(long pos)
{
    this->pos = pos;
}

void ElementProxy::setVector(SparseVector& v)
{
    this->v = v;
}















/*

SparseVector SparseVector::operator*(int x)
{

}

int SparseVector::operator*(SparseVector v)
{

}*/

const ElementProxy SparseVector::operator[](long pos)
{
ElementProxy * t = new ElementProxy(*this, pos);
//printf("ElementProxy %l created successfully. \n",pos);
return *t;

}


 SparseVector SparseVector::operator+(const SparseVector& v)
{
	SparseVector temp;
	
	const ElementNode * current1 = this->getHead();
	const ElementNode * current2 = v.getHead();

	int holder = 0;
	int i = 0;


	/*
	while(current1 !=NULL && current2!=NULL)
	{

	if(current1->pos > current2->pos)
	{

	current2=current2->next;
	}

	else if(current1->pos < current2->pos)
	{
	current1=current1->next;
	}

	else
	{
	insert_element(&temp, current1->pos, (current1->data + current2->data));
	current1=current1->next;

	}
	}*/

	while (current1 != NULL || current2 != NULL)
	{
		/* printf("Inserting element %i into new vector.\n", i);*/
		/*
		printf("Current loop:  %i\n", i);
		printf("Current positions in curr1, cur2:  (%i, %i)\n", current1->pos, current2->pos);

		*/     holder = this->Get(i) + v.Get(i);

		/*  printf("a+b = holder:  %i + %i = %i", a, b, holder);
		printf("Holder value assigned:  %i\n", holder);*/

	if (holder != 0)
	{
	
		temp.Insert(holder, i);
	}



	if (current1 != NULL  &&  i == current1->pos)
	{

		current1 = current1->next;


	}

	if (current2 != NULL && i == current2->pos)
	{

		current2 = current2->next;

	}


	i++;


	}

		return temp;

	
}


SparseVector SparseVector::operator*(int t)
{
	ElementNode* x = this->getHead();

	while (t)
	{
		x->data = x->data * t;
	}
	return *this;
}



const SparseVector& SparseVector::operator=( const SparseVector& v1)
{
	printf("Calling assignment operator\n");

	ElementNode * thisStart = this->getHead();
	ElementNode * inputStart = v1.getHead();
	
	while (thisStart || inputStart)
	{
		if(inputStart->pos > thisStart->pos)
		{
			this->Delete( thisStart->pos);
			thisStart = thisStart->next;
		}

		else
		{
			this->Insert(inputStart->data, inputStart->pos);
			inputStart = inputStart->next;
		}
/*
		if(thisStart)
		{
			thisStart = thisStart->next;
		}

		if (inputStart)
		{
			inputStart = inputStart->next;
		}

		else
		{ }
		*/
	}

	//if it broke because thisStart == NULL, continue inserting until inputStart == NULL
	//if it broke because inputStart==NULL, zero out everything else in this


	return *this;

}





int SparseVector::operator*(const SparseVector& v1)
{
	int temp = 0;

	const ElementNode * current1 =this->getHead();
	const ElementNode * current2 = v1.getHead();


	while (current1 != NULL && current2 != NULL)
	{
		if (current1->pos > current2->pos)
		{
			current2 = current2->next;
		}

		else if (current1->pos < current2->pos)
		{
			current1 = current1->next;
		}

		else
		{
			temp = temp + (current1->data * current2->data);
			current1 = current1->next;

		}
	}

	return temp;



}









}

