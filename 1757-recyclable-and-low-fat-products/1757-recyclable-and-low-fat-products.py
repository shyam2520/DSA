import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    # print(type(products['low_fats'][0]))
    return products[(products['low_fats']=='Y') & 
                    (products['recyclable']=='Y')]['product_id'].to_frame()