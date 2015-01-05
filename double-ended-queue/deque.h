
#define MAX_LEN 10
#define EMPTY   5
#define FULL    (MAX_LEN - 1)

struct deque {
	char s[MAX_LEN];
	int  front;
	int  rear;
};

typedef struct deque        deque;
typedef enum {false, true}  boolean;
typedef char                data;

void reset(deque *);
void advance_front(deque *);
void advance_rear(deque *);
void add_to_front(deque *, data);
void add_to_rear(deque *, data);
data take_from_front(deque *);
data take_from_rear(deque *);
boolean empty(deque *);
boolean full(deque *);


void reset(deque *q)
{
	q -> front = EMPTY;
	q -> rear  = EMPTY;
};

void advance_front(deque *q)
{
	if (q -> front > 0)
		q -> front--;
	else
		q -> front = FULL;
};

void advance_rear(deque *q)
{
	if (q -> rear < FULL)
		q -> rear++;
	else
		q -> rear = 0;
};

void add_to_front(deque *q, data d)
{
	if (!full(q)) {
		advance_front(q);
		q -> s[q -> front] = d;
	};
};

void add_to_rear(deque *q, data d)
{
	if (!full(q)) {
		advance_rear(q);
		q -> s[q -> rear] = d;
	};
};

data take_from_front(deque *q)
{
	data *d;

	*d = q -> s[q -> front];
	q -> front++;
	return *d;
};

data take_from_rear(deque *q)
{
	data *d;

	*d = q -> s[q -> rear];
	q -> rear++;
	return *d;
};

boolean empty(deque *q)
{
	return (q -> front == q -> rear);
};

boolean full(deque *q)
{
	return ((q -> front - q -> rear == 1) || (q -> rear - q -> front == FULL));
};
