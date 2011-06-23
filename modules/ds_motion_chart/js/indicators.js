
  google.load('visualization', '1', {'packages':['motionchart']});

  function changeData() {
    // build up select clasue of query string
    var colFragment = '';
    for (i=0; i<119; i++) {
      colFragment += 'col'+i+', ';
    }
    colFragment = colFragment.substr(0, colFragment.length-2);
  
    var queryText = encodeURIComponent("SELECT "+colFragment+" FROM 971772 skip 0 limit 999999");
    var query = new google.visualization.Query('http://www.google.com/fusiontables/gvizdata?tq='  + queryText);
    query.send(getData);
  }

  function getData(response) {
    var motionchart = new google.visualization.MotionChart(
       document.getElementById('visualization'));
 
    var table = response.getDataTable();

    var labels = getLabels();

    // labels get truncated to 10 chars in fusion tables, so we'll override them here
    for(i=0;i<labels.length;i++)
    {
      table.setColumnLabel(i,  labels[i]);
    }

    var options = {};
    options['state'] = getState();
    options['width'] = 800;
    options['height'] = 500;

    motionchart.draw(table, options);  
  }
/*$(document).ready( function(){
    changeData();
  }
);
*/

function getState() {
  return '{"orderedByX":false,"duration":{"multiplier":1,"timeUnit":"D"},"nonSelectedAlpha":0.4,"iconKeySettings":[],"colorOption":"_UNIQUE_COLOR","xZoomedDataMax":418,"time":"2002","yLambda":1,"sizeOption":"106","yAxisOption":"52","xLambda":1,"iconType":"BUBBLE","xAxisOption":"55","yZoomedDataMax":9,"xZoomedIn":false,"orderedByY":false,"yZoomedIn":false,"yZoomedDataMin":0,"dimensions":{"iconDimensions":["dim0"]},"xZoomedDataMin":54,"uniColorForNonSelected":false,"showTrails":false,"playDuration":15000};';
}

function getLabels() {
  return  ["Area","Year","Gender","Mycoses Mortality by LAD","IX Diseases of the circulatory system Mortality by LAD","Pedal cyclist injured in transport accident Mortality by LAD","Malignant neoplasm of larynx Mortality by LAD","Renal failure Mortality by LAD","Cerebral infarction Mortality by LAD","Other heart diseases Mortality by LAD","Malignant neoplasm of trachea, bronchus and lung Mortality by LAD","Alzheimer's disease Mortality by LAD","Ischaemic heart diseases other than myocardial infarction Mortality by LAD","IV Endocrine, nutritional and metabolic diseases Mortality by LAD","Congenital malformations of the circulatory system Mortality by LAD","Malignant neoplasm of prostate Mortality by LAD","Sequelae of tuberculosis Mortality by LAD","Intestinal infectious diseases Mortality by LAD","Hernia Mortality by LAD","Anaemias Mortality by LAD","Malignant neoplasm of rectosigmoid junction, rectum and anus Mortality by LAD","Diseases of the liver Mortality by LAD","Bronchitis, emphysema and other chronic obstructive pulmonary disease Mortality by LAD","Assault Mortality by LAD","Multiple sclerosis Mortality by LAD","XII Diseases of the skin and subcutaneous tissue Mortality by LAD","XV Pregnancy, childbirth and the puerperium Mortality by LAD","Car occupant injured in transport accident Mortality by LAD","Intracranial haemorrhage Mortality by LAD","Asthma and status asthmaticus Mortality by LAD","Malignant neoplasm of ovary Mortality by LAD","Malignant neoplasm of breast Mortality by LAD","Malignant neoplasms of independent (primary) multiple sites Mortality by LAD","Other ill-defined and unspecified causes of mortality Mortality by LAD","Senility without mention of psychosis Mortality by LAD","Malignant neoplasm of kidney, except renal pelvis Mortality by LAD","Aortic aneurysm and dissection Mortality by LAD","Other accidents Mortality by LAD","Hodgkin's disease Mortality by LAD","XVI Certain conditions originating in the perinatal period Mortality by LAD","Malignant neoplasm of liver and intrahepatic bile ducts Mortality by LAD","Chronic rheumatic heart diseases Mortality by LAD","Meningitis (excluding meningoccal) Mortality by LAD","Septicaemia Mortality by LAD","Human immunodeficiency virus [HIV] disease Mortality by LAD","Mesothelioma Mortality by LAD","Pneumonia Mortality by LAD","Stroke, not specified as haemorrhage or infarction Mortality by LAD","VIII Diseases of the ear and mastoid process Mortality by LAD","Sudden infant death syndrome Mortality by LAD","Malignant neoplasm of colon Mortality by LAD","Parkinson's disease Mortality by LAD","Malignant melanoma of skin Mortality by LAD","III Diseases of the blood and blood-forming organs and certain disorders involving the  immune mechanism Mortality by LAD","Malignant neoplasm of oesophagus Mortality by LAD","II Neoplasms Mortality by LAD","Diabetes mellitus Mortality by LAD","Motor neuron disease Mortality by LAD","Malignant neoplasm of testis Mortality by LAD","Epilepsy Mortality by LAD","Osteoporosis Mortality by LAD","Land transport accidents Mortality by LAD","Phlebitis and thrombophlebitis Mortality by LAD","Malignant neoplasm of other and unspecified parts of uterus Mortality by LAD","I Certain infectious and parasitic diseases Mortality by LAD","Kaposi's sarcoma Mortality by LAD","Cerebrovascular diseases Mortality by LAD","Malignant neoplasms of digestive organs Mortality by LAD","Occupant of heavy transport vehicle injured in transport accident Mortality by LAD","Respiratory tuberculosis Mortality by LAD","Accidental poisoning by and exposure to other and unspecified drugs, medicaments and biological substances Mortality by LAD","VII Diseases of the eye and adnexa Mortality by LAD","XIII Diseases of the musculoskeletal system and connective tissue Mortality by LAD","VI Diseases of the nervous system Mortality by LAD","Pedestrian injured in transport accident Mortality by LAD","Malignant neoplasm of pancreas Mortality by LAD","Myeloid leukaemia Mortality by LAD","Motorcycle rider injured in transport accident Mortality by LAD","V Mental and behavioural disorders Mortality by LAD","Gastric and duodenal ulcer Mortality by LAD","XI Diseases of the digestive system Mortality by LAD","Intentional self-harm; and event of undetermined intent Mortality by LAD","Diseases of appendix Mortality by LAD","Meningococcal infection Mortality by LAD","XVIII Symptoms, signs and abnormal clinical and laboratory findings, not elsewhere classified Mortality by LAD","Vascular and unspecified dementia Mortality by LAD","Atherosclerosis Mortality by LAD","Viral hepatitis Mortality by LAD","Leukaemia Mortality by LAD","Other tuberculosis Mortality by LAD","Hypertensive diseases Mortality by LAD","Multiple myeloma and malignant plasma cell neoplasms Mortality by LAD","Malignant neoplasm of stomach Mortality by LAD","Hyperplasia of prostate Mortality by LAD","Accidents Mortality by LAD","Acute myocardial infarction Mortality by LAD","Glomerular and renal tubulo-interstitial diseases Mortality by LAD","In situ and benign neoplasms, and neoplasms of uncertain or unknown behaviour Mortality by LAD","Occupant of pick-up truck or van injured in transport accident Mortality by LAD","Influenza Mortality by LAD","Other malignant neoplasms of skin Mortality by LAD","Ischaemic heart diseases Mortality by LAD","XVII Congenital malformations, deformations and chromosomal abnormalities Mortality by LAD","Rheumatoid arthritis and juvenile arthritis Mortality by LAD","X Diseases of the respiratory system Mortality by LAD","Mental and behavioural disorders due to psychoactive substance use Mortality by LAD","Malignant neoplasms of eye, Mortality by LAD","brain and other parts of brain and other parts of central nervous system Mortality by LAD","Transport accidents including sequelae of transport accidents Mortality by LAD","Accidental poisoning by and exposure to noxious substances Mortality by LAD","Malignant neoplasm of bladder Mortality by LAD","Malignant neoplasm of cervix uteri Mortality by LAD","Diverticular disease of intestine Mortality by LAD","XX External causes of morbidity and mortality Mortality by LAD","XIV Diseases of the genitourinary system Mortality by LAD","Non-Hodgkin's lymphoma Mortality by LAD","Malignant neoplasms Mortality by LAD","Malignant neoplasm of gallbladder and biliary tract Mortality by LAD","Malignant neoplasms of lip, oral cavity and pharynx Mortality by LAD"];
}