import math
import numpy as np

def calculate_RMSE (y_pred, y_ref):
    MSE = np.square(np.subtract(y_pred,y_ref)).mean()
    RMSE = np.sqrt(MSE)
    return RMSE

def calculate_RRMSE (y_pred, y_ref):
    y_pred = np.array(y_pred)
    y_ref = np.array(y_ref)
    num = np.sum(np.square(y_ref - y_pred))
    den = np.sum(np.square(y_pred))
    squared_error = num/den
    rrmse_loss = np.sqrt(squared_error)
    return rrmse_loss

y_ref = [1.0, 2.0, 3.0, 4.0, 5.0]
y_pred = [1.6, 2.5, 2.9, 3.0, 4.1]

RMSE = calculate_RMSE(y_pred, y_ref)
RRMSE = calculate_RRMSE(y_pred, y_ref)
print("RMSE calculate using NumPy = %.10lf" % (RMSE))
print("RRMSE calculate using NumPy = %.10lf" % (RRMSE))