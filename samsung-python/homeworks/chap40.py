# %%
import pandas as pd
import numpy as np 
import datetime
import matplotlib.pyplot as plt 
from datetime import date, datetime, time, timezone

df = pd.read_csv("./data/mini-project-datasources/covid-vaccination-doses-per-capita.csv")

# %%
df.info()

# %%
df["date"] = pd.to_datetime(df["Day"])
df.set_index("Date", inplace=True)
df.drop(["Drop"], axis=1, inplace=True)

df.head()

# %%
len(df["Entity"].unique())

# %%
covid_c = df.groupby(["Entity"])

# %%
for key, group in covid_c:
  print("+key:", key)
  print("+number:", len(group))
  print(group.head())
  print("\n")

# %%
total_df = covid_c.sum()
total_df.head()

# %%
import folium

map = folium.Map(location=[37.2594750011864, 127.05145091394964],
                 zoom_start=13,
                 )

map

# %%
marker_map = folium.Map(location=[45.372, -121.69772], zoom_start=12, titles="Stamen Terrian")

folium.Marker(
  location=[45.3288, -121.7113],
  popup="",
  icon=folium.Icon(icon=""),
).add_to(marker_map)

folium.Marker(
  location=[45.3288, -121.7113],
  popup="",
  icon=folium.Icon(icon=""),
).add_to(marker_map)

folium.CircleMarker(
  location=[45.3800, -121.6000],
  radius=100,
  popup="circle",
  fill=True,
  fill_color="#3186cc",
).add_to(marker_map)

marker_map

# %%
import pandas as pd

url = (
  "https://raw.githubusercontent.com/python-visualization/folium/master/examples/data"
)

state_geo = f"{url}/us-states.json"
state_unemployment = f"{url}/US_Unemployment_Oct2012.csv"
state_data = pd.read_csv(state_unemployment)

m = folium.Map(location=[48, -102], zoom_start=3)

folium.Choropleth(
  geo_data=state_geo,
  name="choropleth",
  data=state_data,
  columns=["State", "Unemployment"],
  key_on="feature.id",
  fill_opacity=0.7,
  line_opacity=0.2,
  legend_name="Unemployment Rate (%)",
).add_to(m)

folium.LayerControl().add_to(m)

m

# %%
import folium
import json

center = [35.762887375145795, 84.80313219586536]

m = folium.Map(location=center, zoom_start=2,
               max_bounds=True,
               min_zoom=1, min_lat=-84,
               max_lat=84, min_lon=-175, max_lon=187,
              )

geo_path = "./data//world_geojson/world_Countries_Generalized_.geojson"

json_data = json.load(open(geo_path, encoding="utf-8"))

folium.Choropleth(
  geo_data=json_data,
  data=total_df,
  columns=(total_df.index, "total_vaccinations_per_hundred"),
  key_on="properties.COUNTRY",
  fill_color="RdYlGn",
  fill_opacity=0.7,
  line_opacity=0.2,
).add_to(m)

folium.LayerControl().add_to(m)

# %%
m


