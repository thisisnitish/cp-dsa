/* This question is not on the Leetcode as of now, so I'm doing this one 
for learning purpose, I am assuming that we know how to create a Linked 
List, and and how to detect the loop in a Linked List. So, i will directly
write the function for deleting the loop of Linked List.

The basic idea is, we will be using Floyd's Tortoise and Hare Algorithm
and when the hare and tortoise meet at same point then move anyone hare 
or tortoise to head and start traversing both hare and tortoise one by 
one and check if the next node is same, As you get the next node same, 
whichever you haven't move to the head earlier put NULL in their next.
*/

void deleteLoop(node* &head){
    node* hare = head;
    node* tortoise = head;

    while(hare && hare->next){
        hare = hare->next->next;
        tortoise = tortoise->next;

        if(hare == tortoise){

            /*you can do the vice versa also*/
            tortoise = head;

            while(tortoise->next != hare->next){
                tortoise = tortoise->next;
                hare = hare->next;
            }
            hare->next = NULL;
        }
    }
}
