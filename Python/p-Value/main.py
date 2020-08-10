# =======================================================================================
# Simple program that demonstrate how to calculate the p-value using Linear Regression
# OBS: This program will only run using Python 3
# =======================================================================================

import pandas as pd
import statsmodels.formula.api as smf

df = pd.read_csv("mtcars.csv")
#print(df.head())

# Perform the regression using the columns 'mpg' and 'wt'
model = smf.ols("mpg ~ wt", data=df).fit()

# Show the results
#print(model.summary())
print(model.pvalues)

pvalue = model.pvalues[1]
alpha = 0.05
if (pvalue <= alpha):
	print("Alternate Hypothesis")
else:
	print("Null Hypothesis")

