grammar Expr;
expr:
	expr op = '+' term		# Add
	| expr op = '-' term	# Sub
	| term					# ExpTerm;
term:
	term op = '*' factor	# Mul
	| term op = '/' factor	# Div
	| factor				# TermFactor;
factor: atom = INT # number | '(' expr ')' # FactorExpr;
INT: [0-9]+;
WS: [ \t\n\r]+ -> skip;