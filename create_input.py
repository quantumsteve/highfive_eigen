import h5py
import numpy as np

g = h5py.File('pos_rows.h5','w')
pos = np.ones((3,300000000),dtype='float32')
g.create_dataset("positions", data=pos)

g = h5py.File('pos_cols.h5','w')
g.create_dataset("positions", data=np.transpose(pos))

