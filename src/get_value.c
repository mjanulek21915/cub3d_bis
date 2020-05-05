int				get_value(char **buff)
{
	int rst = 0;

	next_line(buff);
	while (**buff >= '0' && **buff <= '9')
	{
		rst = (rst * 10) + **buff - '0';
		(*buff)++;
	}
	end_line(buff);
	return (rst);
}