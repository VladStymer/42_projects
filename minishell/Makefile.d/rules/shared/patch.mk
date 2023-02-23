NORME_PATCH		:=	$(addprefix norme-patch-, $(SRCS))
norme-patch-%:		$(SRCS_DIR)/%
					sed -i -r '/if \(DEBUG[^\}]+/,+1d' $<

norme-unpatch:
					patch -R patches/debug.patch
					rm patches/debug.patch

check_unstaged:
					# TODO: check that there are no unstaged changes in $(SRCS)
					echo OK

norme-patch:		check_unstaged $(NORME_PATCH) 
					diff $(SRCS_DIR) >> patches/debug.patch
