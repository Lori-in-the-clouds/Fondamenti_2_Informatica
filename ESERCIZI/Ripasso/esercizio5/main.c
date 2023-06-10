extern int ContaOccorrenze(const char* filename, const char* str);

int main(void) {
	const char file[] = "file2.txt";
	const char str[] = "file";
	ContaOccorrenze(file, str);
}