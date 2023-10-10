void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*byte_ptr;
	unsigned char	byte_value;

	byte_value = (unsigned char) c;
	byte_ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		byte_ptr[i] = byte_value;
		i++;
	}
	return (b);
}
