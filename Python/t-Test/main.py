import pandas as pd
import numpy as np
import statsmodels.stats.weightstats as sm
from scipy import stats

# Two-Sample T-Test
df = pd.read_csv("samples.csv")
#print(df.head())

ttest = sm.ttest_ind(df["s1"],df["s2"])
pvalue = ttest[1]
alpha = 0.05

if (pvalue <= alpha):
	print("Alternate Hypothesis")
else:
	print("Null Hypothesis")


# One-Sample T-Test
np.random.seed(7654567)  # fix seed to get the same result
rvs = stats.norm.rvs(loc=5, scale=10, size=(50,2))
print(np.mean(rvs))
print(stats.ttest_1samp(rvs,5.0))