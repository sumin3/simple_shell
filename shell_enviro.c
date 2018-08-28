#include "holberton.h"
/**
 *   free_list - frees memory for list
 *    @head: pointer to head of list
 */
void free_list(list_t *head)
{
	if (head)
	{
		if (head->next)
			free_list(head->next);
		free(head->key);
		free(head);
	}
}
/**
 * add_node - adds a node to the beginning of a singly linked list
 * @head: Pointer of pointer to the head of list
 * @key: key of node
 * @val: value of node
 * Return: pointer to the linked list
 */
list_t *add_node(list_t **head,  char *key,  char *val)
{
	list_t *tmp_node;

	tmp_node = malloc(sizeof(list_t));
	if (!tmp_node)
		return (NULL);
	tmp_node->key = key;
	tmp_node->val = val;
	tmp_node->next = *head;
	*head = tmp_node;
	return (*head);
}
/**
 * delete_node_at_index - deletes a node at index given
 * @head: pointer to pointer of head of list
 * @index: element to delete
 * Return: 1 if deletion successful -1 if failed
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *prev_node = NULL;
	list_t *tgt_node = NULL;
	unsigned int counter = 0;

	if (!*head)
		return (-1);
	tgt_node = *head;
	while (counter < index && tgt_node)
	{
		prev_node = tgt_node;
		tgt_node = tgt_node->next;
		counter++;
	}
	if (counter != index)
		return (-1);
	if (!prev_node)
		*head = tgt_node->next;
	else
		prev_node->next = tgt_node->next;
	free(tgt_node->key);
	free(tgt_node);
	return (1);
}

/**
 * get_env - makes a copy of the environment variablesk
 * @head: pointer to pointer to head of list
 * @env: pointer to pointer of env to make copy of
 */
void get_env(list_t **head, char **env)
{
	int row = 0;
	char *temp_key,  *temp_val;
	char *tempstr;

	while (env && env[row])
	{
		tempstr = _strdup(env[row]);
		temp_val = make_key_val(tempstr);
		temp_key = tempstr;
		*head = add_node(head, temp_key, temp_val);
		row++;
	}
}
/**
 * make_key_val - takes a string and split it into key value pair
 * @tempstr: string to split
 * Return: the value
 */
char *make_key_val(char *tempstr)
{
	int col = 0;
	char *temp_val;

	while (tempstr[col] != '=' && tempstr[col])
		col++;
	temp_val = &tempstr[col + 1];
	tempstr[col] = '\0';
	return (temp_val);
}
