#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _student {
	int		    id;
	char		name[100];
	float		gpa;
} student;


// nó
typedef struct _node {
	student		k;
	struct _node	*next; // ponteiro para o próximo elemento
} node, *list;


void insert_list (list *L, student k) {
	node	*p;
	p = (node *) malloc (sizeof (node));
	p->k = k;
	p->next = *L;

	*L = p;
}


student *search_list (list L, int id) {
	node	*p;

	for (p=L; p && p->k.id != id; p=p->next);

	if (p)
		return &p->k;
	else
		return NULL;
}

/* cria uma lista vazia */
void create_list (list *L) {
	*L = NULL;
}


int main () {
	
	setlocale(LC_ALL,"portuguese");
	
	list		C;	/* a class of students */
	student		s, *p;
	int		    id;
	FILE		*f;



	f = fopen ("./List.txt", "r");
	if (!f) {
		perror ("List");
		exit (1);
	}

	create_list (&C);

	for (;;) {
		fscanf (f, "%d %s %f\n", &s.id, s.name, &s.gpa);
		if (feof (f))
      break;
		insert_list (&C, s);
	}
	fclose (f);

	for (;;) {
		printf ("Entre com o ID do estudante. 0 (zero) para SAIR: ");
		scanf ("%d", &id);

		if (id == 0)
       break;

		p = search_list (C, id);


		if (!p)
			printf ("ID #%d não encontrado!\n", id);
		else
			printf ("%d\t %s\t %0.2f\n", p->id, p->name, p->gpa);
	}
	exit (0);
}
