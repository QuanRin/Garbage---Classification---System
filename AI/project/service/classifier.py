TYPES = {
    "BATTERY":"battery",
    "CARTON":'Carton',
    "CLOTHES":'Clothes',
    "EGGSHELLS":'Eggshells',
    "ELECTRONIC":'Electronic',
    "FOOD":"Food",
    "GLASS":'Glass',
    "HAZARDOUS_BOX":'Hazad-box',
    "LIGHT":'Light',
    "MASK":'Mask',
    "MEDICINE":'Medicine',
    "MER_THERM":'Mer-therm',
    "METAL_CAN":'Metal can',
    "MILK":'Milk',
    "NR PLASTIC":'Nr plastic',
    "PAPER":'Paper',
    "PLASTIC":'Plastic',
    "TEA_BAGS":'Tea bags',
    "TOBACO":'Tobacco'
}

CLASSIFICATION = {
    "HAZARDOUS":"hazadous",
    "GLASS" :"glass",
    "OTHER":"other",
    "RECYCLE":"recycle"
}
def classifier(type):
    # print(type)
    TPS = TYPES.get(type.upper()).upper()
    print(TPS)
    match TPS:
        case "BATTERY" | "HAZARDOUS_BOX" | "MEDICINE" | "NR_PLASTIC" | "TOBACO" | "ELECTRONIC" | "LIGHT" | "MER_THERM" | "ELECTRONIC":
            return CLASSIFICATION.get("HAZARDOUS"), TPS
        case "CARTON" | "CLOTHES" | "EGGSHELLS" | "MASK" | "PAPER" | "METAL_CAN" | "MILK" | "PLASTIC":
            return CLASSIFICATION.get("RECYCLE"), TPS
        case "GLASS":
            return CLASSIFICATION.get("GLASS"), TPS
        case "FOOD" |  "TEA_BAGS":
            return CLASSIFICATION.get("OTHER"),TPS
        case _:
            return "UNKNOW" , TPS
        