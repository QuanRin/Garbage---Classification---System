import pickle
import joblib
from keras.models import load_model as lm

model = None
types = None


def load_model():
    global model
    global types
    if not model:
        print("true not model")
        # model_path = open("model-5-12-t","rb")
        temp = joblib.load("model-1")
        model = temp
        # model_path.close()
    return model, [
        'NR plastic',
        'battery',
        'carton',
        'clothes',
        'eggshells',
        'electronic',
        'food',
        'glass',
        'hazard-box',
        'mask',
        'medicine',
        'metal can',
        'paper',
        'plastic',
        'tea bags',
        'tobacco'
    ]


def load_model_2():
    global model
    if not model:
        temp = lm("model.h5")
        model = temp
        # model_path.close()
    return model, [
        'NR plastic',
        'battery',
        'carton',
        'clothes',
        'eggshells',
        'electronic',
        'food',
        'glass',
        'hazard-box',
        'mask',
        'medicine',
        'metal can',
        'paper',
        'plastic',
        'tea bags',
        'tobacco'
    ]
