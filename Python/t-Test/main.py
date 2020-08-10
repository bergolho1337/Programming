import pandas as pd
import statsmodels.stats.weightstats as sm

df = pd.read_csv("samples.csv")
#print(df.head())

ttest = sm.ttest_ind(df["s1"],df["s2"])
pvalue = ttest[1]
alpha = 0.05

if (pvalue <= alpha):
	print("Alternate Hypothesis")
else:
	print("Null Hypothesis")

