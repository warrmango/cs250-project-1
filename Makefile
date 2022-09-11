
goal: git-commit convert test_bits 

convert: convert.c
	gcc -g -o convert convert.c

test_bits: test_bits.c
	gcc -g -o test_bits test_bits.c bits.c

clean:
	rm -f convert test_bits

.PHONY: git-commit
git-commit:
	git checkout master >> .local.git.out || echo
	git add *.c Makefile >> .local.git.out  || echo
	git commit -a -m 'Commit' >> .local.git.out || echo
	git push origin master

