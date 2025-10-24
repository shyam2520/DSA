import pandas as pd

def big_countries(df: pd.DataFrame) -> pd.DataFrame:
    return df[(df['population']>=25000000) | (df['area']>=3000000) ][['name','population','area']]