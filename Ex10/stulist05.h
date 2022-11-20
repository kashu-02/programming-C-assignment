/* struct declaration */
typedef struct {
  int id;
  char surname[12];
  char givenname[12];
  char class[3];
} Record;

typedef struct node *NodePointer;

struct node {
  Record key;
  NodePointer next;
};

/* prototype declaration */
NodePointer insert(Record*);
NodePointer finditem(int);
void listprint(void);
NodePointer make_1node(Record *, NodePointer);
void listprint_sel(char *);

/* Global Variable head */
NodePointer head;
