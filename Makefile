all:
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C myTerm
	$(MAKE) -C console
clean:
	$(MAKE) clean -C mySimpleComputer
	$(MAKE) clean -C myTerm 
	$(MAKE) clean -C console
