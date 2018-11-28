#------------------------------------------------------------------------------
# primary source: .eps
# store ROOT plots in .eps format, make .png and .pdf out of .eps files
#------------------------------------------------------------------------------
dir=.

pdfs := $(patsubst figures/eps/%.eps, figures/pdf/%.pdf,  $(wildcard figures/eps/*.eps ))

pngs := $(patsubst figures/eps/%.eps, figures/png/%.png, $(wildcard figures/eps/*.eps ))

figures/pdf/%.pdf: figures/eps/%.eps
	ps2pdf -dEPSCrop $? $@

figures/png/%.png: figures/eps/%.eps
	convert -density 400 -depth 8 -quality 85  $? $@

pdf: $(pdfs) 
# 	echo $?
png: $(pngs) 
# 	echo $?

mu2e_22262: mu2e_22262.tex input_data.tex fits.tex detector_response.tex
	if [ ! -f tmp ] ; then mkdir tmp ; fi ; \
	pdflatex -output-directory=tmp mu2e_22262.tex input_data.tex fits.tex detector_response.tex; \
	bibtex tmp/mu2e_22262 ; \
	pdflatex -output-directory=tmp mu2e_22262.tex input_data.tex fits.tex detector_response.tex

all: pdf mu2e_22262
	echo $(pdfs)
	echo $?
