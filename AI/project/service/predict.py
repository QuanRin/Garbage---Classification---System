from project.service.load_model import load_model,load_model_2
import numpy as np

def predict(img):
    model,types = load_model()
    pre = model.predict(img)
    return types[pre[0]]

def predict_2(img):
    model,types = load_model_2()
    pre = model.predict(img)

    # print(pre)
    return types[np.argmax(pre[0])]