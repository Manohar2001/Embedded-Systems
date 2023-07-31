var sheet_id = "1ReKdbZrT2e5qlwbg_hHzKK0L-X_nI18vc3-gKS5_yLA";
var sheet_name = "BT20ECE051";
function doGet(e){
  var ss = SpreadsheetApp.openById(sheet_id);
  var sheet = ss.getSheetByName(sheet_name);
  var data = sheet.getDataRange().getValues();
  var username = e.parameter.username;
  var password = e.parameter.password;
  var f = Number(e.parameter.flag);
  var debit_amount = Number(e.parameter.Debit_amount);
  var credit_amount = Number(e.parameter.Credit_amount);
  
  if(f == 1){
  for (var i=0;i<data.length;i++){
    if (data[i][0]==username){
      if(data[i][1]==password){
        return ContentService.createTextOutput("success");
      }
    }
  }
  }
  if(f==2){
    for(var i=0;i<data.length;i++){
      if(data[i][0]==username){
        if(data[i][1]==password){
          var amount_available=sheet.getRange(i+1,3);
          if(amount_available.getValue()>=debit_amount)
          {
            return ContentService.createTextOutput("success");
          }
        }
      }
    }
  }
  else if(f==3){
    for(var i=0;i<data.length;i++){
      if(data[i][0]==username){
        if(data[i][1]==password){
          sheet.getRange(i+1,5).setValue(debit_amount);
          var aval_bal=sheet.getRange(i+1,6);
          var debit=sheet.getRange(i+1,5);
          var amount_rem=aval_bal.getValue()-debit.getValue();
          sheet.getRange(i+1,6).setValue(amount_rem);
          return ContentService.createTextOutput(amount_rem);
        }
      }
    }
  }
  else if(f==4){
    for(var i=0;i<data.length;i++){
      if(data[i][0]==username){
        if(data[i][1]==password){
          sheet.getRange(i+1,4).setValue(credit_amount);
          var aval_bal=sheet.getRange(i+1,6);
          var credit=sheet.getRange(i+1,4);
          var balance_aval=aval_bal.getValue()+credit.getValue();
          sheet.getRange(i+1,6).setValue(balance_aval);
          return ContentService.createTextOutput(balance_aval);
        }
      }
    }
  }
  else if(f==5){
    for(var i=0;i<data.length;i++){
      if(data[i][0]==username){
        if(data[i][1]==password){
          var avail_bal=sheet.getRange(i+1,6);
          var money=avail_bal.getValue();
          return ContentService.createTextOutput(money);
        }
      }
    }
  }

  return ContentService.createTextOutput("fail");
}
