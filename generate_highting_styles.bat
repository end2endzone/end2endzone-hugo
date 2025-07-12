:: Documentation https://gohugo.io/content-management/syntax-highlighting/#generate-syntax-highlighter-css
:: Styles examples are available at https://xyproto.github.io/splash/docs/
::
:: --highlightStyle "#f8f8f2 bg:#000000"
:: --linesStyle string
::
:: Names of interresting styles for end2endzone:
:: - dracula
:: - fruity
:: - monokai
:: - native
:: - solarized-dark
::

@echo off
set PATH=D:\Apps\Hugo\0.87.0\bin;%PATH%

echo Generating styles...
@echo on
hugo gen chromastyles --style=monokai>static\css\syntax.css
@echo off

pause
