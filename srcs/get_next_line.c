#include "../headers/get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	char		*ret;
	char		*buf;
	static char	*ptr;
	int			out;

	out = -69;
	while ((out > 0 && ptr) || out == -69)
	{
		str = gnl_alloc(BUFFER_SIZE + 1, sizeof(char));
		if (!str)
			break ;
		out = read(fd, str, BUFFER_SIZE);
		buf = f_strjoin(ptr, str);
		ptr = buf;
		ret = gnl_line(ptr);
		if (sl(ret) > 0
			&& (ret[sl(ret) - 1] == '\n' || (out < BUFFER_SIZE && out >= 0)))
		{
			ptr += sl(ret) + (*buf == 127);
			return (ret);
		}
		free(ret);
	}
	return (gnl_clean(buf, &ptr));
}
