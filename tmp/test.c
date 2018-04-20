
void	change_str(char *str)
{
	str[0] = 'H';
}

int		main(int argc, char **argv)
{
	char str[] = "abcde";
	printf("%s\n",str);
	change_str(str);
	printf("%s\n", str);

}
