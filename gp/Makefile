all: gplib

gplib: *.gp
	@echo "libfact=\"$(SHAREDLIB_PATH)\";" > temp
	@echo "install(\"replace_eol\",\"vs\",\"replace_eol\",libfact);" >> temp
	@cat temp gp/*.gp > libfact.gp 
	@rm -f temp
