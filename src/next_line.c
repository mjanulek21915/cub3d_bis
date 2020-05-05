void			next_line(char **buff)
{
	while (**buff != '\n')
		(*buff)++;
	(*buff)++;
}