import pandas as pd
import numpy
import os

data = pd.read_csv("waste_items_dataset.csv")
data_cleaned = data.drop_duplicates()

data_cleaned.to_csv('waste_items_dataset.csv', index=False)
