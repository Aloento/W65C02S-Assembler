(function(){const t=document.createElement("link").relList;if(t&&t.supports&&t.supports("modulepreload"))return;for(const n of document.querySelectorAll('link[rel="modulepreload"]'))o(n);new MutationObserver(n=>{for(const a of n)if(a.type==="childList")for(const i of a.addedNodes)i.tagName==="LINK"&&i.rel==="modulepreload"&&o(i)}).observe(document,{childList:!0,subtree:!0});function r(n){const a={};return n.integrity&&(a.integrity=n.integrity),n.referrerPolicy&&(a.referrerPolicy=n.referrerPolicy),n.crossOrigin==="use-credentials"?a.credentials="include":n.crossOrigin==="anonymous"?a.credentials="omit":a.credentials="same-origin",a}function o(n){if(n.ep)return;n.ep=!0;const a=r(n);fetch(n.href,a)}})();var F,y,ie,T,re,ue,J,D={},pe=[],be=/acit|ex(?:s|g|n|p|$)|rph|grid|ows|mnc|ntw|ine[ch]|zoo|^ord|itera/i,O=Array.isArray;function A(e,t){for(var r in t)e[r]=t[r];return e}function ce(e){var t=e.parentNode;t&&t.removeChild(e)}function ve(e,t,r){var o,n,a,i={};for(a in t)a=="key"?o=t[a]:a=="ref"?n=t[a]:i[a]=t[a];if(arguments.length>2&&(i.children=arguments.length>3?F.call(arguments,2):r),typeof e=="function"&&e.defaultProps!=null)for(a in e.defaultProps)i[a]===void 0&&(i[a]=e.defaultProps[a]);return X(e,i,o,n,null)}function X(e,t,r,o,n){var a={type:e,props:t,key:r,ref:o,__k:null,__:null,__b:0,__e:null,__d:void 0,__c:null,__h:null,constructor:void 0,__v:n??++ie};return n==null&&y.vnode!=null&&y.vnode(a),a}function j(e){return e.children}function Y(e,t){this.props=e,this.context=t}function N(e,t){if(t==null)return e.__?N(e.__,e.__.__k.indexOf(e)+1):null;for(var r;t<e.__k.length;t++)if((r=e.__k[t])!=null&&r.__e!=null)return r.__d||r.__e;return typeof e.type=="function"?N(e):null}function fe(e){var t,r;if((e=e.__)!=null&&e.__c!=null){for(e.__e=e.__c.base=null,t=0;t<e.__k.length;t++)if((r=e.__k[t])!=null&&r.__e!=null){e.__e=e.__c.base=r.__e;break}return fe(e)}}function ae(e){(!e.__d&&(e.__d=!0)&&T.push(e)&&!Z.__r++||re!==y.debounceRendering)&&((re=y.debounceRendering)||ue)(Z)}function Z(){var e,t,r,o,n,a,i,l,m;for(T.sort(J);e=T.shift();)e.__d&&(t=T.length,o=void 0,n=void 0,a=void 0,l=(i=(r=e).__v).__e,(m=r.__P)&&(o=[],n=[],(a=A({},i)).__v=i.__v+1,ee(m,i,a,r.__n,m.ownerSVGElement!==void 0,i.__h!=null?[l]:null,o,l??N(i),i.__h,n),he(o,i,n),i.__e!=l&&fe(i)),T.length>t&&T.sort(J));Z.__r=0}function me(e,t,r,o,n,a,i,l,m,d,b){var s,h,_,f,w,U,v,k,P,$=0,L=o&&o.__k||pe,I=L.length,S=I,B=t.length;for(r.__k=[],s=0;s<B;s++)(f=r.__k[s]=(f=t[s])==null||typeof f=="boolean"||typeof f=="function"?null:typeof f=="string"||typeof f=="number"||typeof f=="bigint"?X(null,f,null,null,f):O(f)?X(j,{children:f},null,null,null):f.__b>0?X(f.type,f.props,f.key,f.ref?f.ref:null,f.__v):f)!=null?(f.__=r,f.__b=r.__b+1,(k=ye(f,L,v=s+$,S))===-1?_=D:(_=L[k]||D,L[k]=void 0,S--),ee(e,f,_,n,a,i,l,m,d,b),w=f.__e,(h=f.ref)&&_.ref!=h&&(_.ref&&te(_.ref,null,f),b.push(h,f.__c||w,f)),w!=null&&(U==null&&(U=w),(P=_===D||_.__v===null)?k==-1&&$--:k!==v&&(k===v+1?$++:k>v?S>B-v?$+=k-v:$--:$=k<v&&k==v-1?k-v:0),v=s+$,typeof f.type!="function"||k===v&&_.__k!==f.__k?typeof f.type=="function"||k===v&&!P?f.__d!==void 0?(m=f.__d,f.__d=void 0):m=w.nextSibling:m=le(e,w,m):m=_e(f,m,e),typeof r.type=="function"&&(r.__d=m))):(_=L[s])&&_.key==null&&_.__e&&(_.__e==m&&(_.__=o,m=N(_)),W(_,_,!1),L[s]=null);for(r.__e=U,s=I;s--;)L[s]!=null&&(typeof r.type=="function"&&L[s].__e!=null&&L[s].__e==r.__d&&(r.__d=L[s].__e.nextSibling),W(L[s],L[s]))}function _e(e,t,r){for(var o,n=e.__k,a=0;n&&a<n.length;a++)(o=n[a])&&(o.__=e,t=typeof o.type=="function"?_e(o,t,r):le(r,o.__e,t));return t}function le(e,t,r){return r==null||r.parentNode!==e?e.insertBefore(t,null):t==r&&t.parentNode!=null||e.insertBefore(t,r),t.nextSibling}function ye(e,t,r,o){var n=e.key,a=e.type,i=r-1,l=r+1,m=t[r];if(m===null||m&&n==m.key&&a===m.type)return r;if(o>(m!=null?1:0))for(;i>=0||l<t.length;){if(i>=0){if((m=t[i])&&n==m.key&&a===m.type)return i;i--}if(l<t.length){if((m=t[l])&&n==m.key&&a===m.type)return l;l++}}return-1}function de(e,t,r,o,n){var a;for(a in r)a==="children"||a==="key"||a in t||H(e,a,null,r[a],o);for(a in t)n&&typeof t[a]!="function"||a==="children"||a==="key"||a==="value"||a==="checked"||r[a]===t[a]||H(e,a,t[a],r[a],o)}function ne(e,t,r){t[0]==="-"?e.setProperty(t,r??""):e[t]=r==null?"":typeof r!="number"||be.test(t)?r:r+"px"}function H(e,t,r,o,n){var a;e:if(t==="style")if(typeof r=="string")e.style.cssText=r;else{if(typeof o=="string"&&(e.style.cssText=o=""),o)for(t in o)r&&t in r||ne(e.style,t,"");if(r)for(t in r)o&&r[t]===o[t]||ne(e.style,t,r[t])}else if(t[0]==="o"&&t[1]==="n")a=t!==(t=t.replace(/(PointerCapture)$|Capture$/,"$1")),t=t.toLowerCase()in e?t.toLowerCase().slice(2):t.slice(2),e.l||(e.l={}),e.l[t+a]=r,r?o?r.u=o.u:(r.u=Date.now(),e.addEventListener(t,a?oe:se,a)):e.removeEventListener(t,a?oe:se,a);else if(t!=="dangerouslySetInnerHTML"){if(n)t=t.replace(/xlink(H|:h)/,"h").replace(/sName$/,"s");else if(t!=="width"&&t!=="height"&&t!=="href"&&t!=="list"&&t!=="form"&&t!=="tabIndex"&&t!=="download"&&t!=="rowSpan"&&t!=="colSpan"&&t!=="role"&&t in e)try{e[t]=r??"";break e}catch{}typeof r=="function"||(r==null||r===!1&&t[4]!=="-"?e.removeAttribute(t):e.setAttribute(t,r))}}function se(e){var t=this.l[e.type+!1];if(e.t){if(e.t<=t.u)return}else e.t=Date.now();return t(y.event?y.event(e):e)}function oe(e){return this.l[e.type+!0](y.event?y.event(e):e)}function ee(e,t,r,o,n,a,i,l,m,d){var b,s,h,_,f,w,U,v,k,P,$,L,I,S,B,x=t.type;if(t.constructor!==void 0)return null;r.__h!=null&&(m=r.__h,l=t.__e=r.__e,t.__h=null,a=[l]),(b=y.__b)&&b(t);e:if(typeof x=="function")try{if(v=t.props,k=(b=x.contextType)&&o[b.__c],P=b?k?k.props.value:b.__:o,r.__c?U=(s=t.__c=r.__c).__=s.__E:("prototype"in x&&x.prototype.render?t.__c=s=new x(v,P):(t.__c=s=new Y(v,P),s.constructor=x,s.render=Le),k&&k.sub(s),s.props=v,s.state||(s.state={}),s.context=P,s.__n=o,h=s.__d=!0,s.__h=[],s._sb=[]),s.__s==null&&(s.__s=s.state),x.getDerivedStateFromProps!=null&&(s.__s==s.state&&(s.__s=A({},s.__s)),A(s.__s,x.getDerivedStateFromProps(v,s.__s))),_=s.props,f=s.state,s.__v=t,h)x.getDerivedStateFromProps==null&&s.componentWillMount!=null&&s.componentWillMount(),s.componentDidMount!=null&&s.__h.push(s.componentDidMount);else{if(x.getDerivedStateFromProps==null&&v!==_&&s.componentWillReceiveProps!=null&&s.componentWillReceiveProps(v,P),!s.__e&&(s.shouldComponentUpdate!=null&&s.shouldComponentUpdate(v,s.__s,P)===!1||t.__v===r.__v)){for(t.__v!==r.__v&&(s.props=v,s.state=s.__s,s.__d=!1),t.__e=r.__e,t.__k=r.__k,t.__k.forEach(function(g){g&&(g.__=t)}),$=0;$<s._sb.length;$++)s.__h.push(s._sb[$]);s._sb=[],s.__h.length&&i.push(s);break e}s.componentWillUpdate!=null&&s.componentWillUpdate(v,s.__s,P),s.componentDidUpdate!=null&&s.__h.push(function(){s.componentDidUpdate(_,f,w)})}if(s.context=P,s.props=v,s.__P=e,s.__e=!1,L=y.__r,I=0,"prototype"in x&&x.prototype.render){for(s.state=s.__s,s.__d=!1,L&&L(t),b=s.render(s.props,s.state,s.context),S=0;S<s._sb.length;S++)s.__h.push(s._sb[S]);s._sb=[]}else do s.__d=!1,L&&L(t),b=s.render(s.props,s.state,s.context),s.state=s.__s;while(s.__d&&++I<25);s.state=s.__s,s.getChildContext!=null&&(o=A(A({},o),s.getChildContext())),h||s.getSnapshotBeforeUpdate==null||(w=s.getSnapshotBeforeUpdate(_,f)),me(e,O(B=b!=null&&b.type===j&&b.key==null?b.props.children:b)?B:[B],t,r,o,n,a,i,l,m,d),s.base=t.__e,t.__h=null,s.__h.length&&i.push(s),U&&(s.__E=s.__=null)}catch(g){t.__v=null,(m||a!=null)&&(t.__e=l,t.__h=!!m,a[a.indexOf(l)]=null),y.__e(g,t,r)}else a==null&&t.__v===r.__v?(t.__k=r.__k,t.__e=r.__e):t.__e=ke(r.__e,t,r,o,n,a,i,m,d);(b=y.diffed)&&b(t)}function he(e,t,r){for(var o=0;o<r.length;o++)te(r[o],r[++o],r[++o]);y.__c&&y.__c(t,e),e.some(function(n){try{e=n.__h,n.__h=[],e.some(function(a){a.call(n)})}catch(a){y.__e(a,n.__v)}})}function ke(e,t,r,o,n,a,i,l,m){var d,b,s,h=r.props,_=t.props,f=t.type,w=0;if(f==="svg"&&(n=!0),a!=null){for(;w<a.length;w++)if((d=a[w])&&"setAttribute"in d==!!f&&(f?d.localName===f:d.nodeType===3)){e=d,a[w]=null;break}}if(e==null){if(f===null)return document.createTextNode(_);e=n?document.createElementNS("http://www.w3.org/2000/svg",f):document.createElement(f,_.is&&_),a=null,l=!1}if(f===null)h===_||l&&e.data===_||(e.data=_);else{if(a=a&&F.call(e.childNodes),b=(h=r.props||D).dangerouslySetInnerHTML,s=_.dangerouslySetInnerHTML,!l){if(a!=null)for(h={},w=0;w<e.attributes.length;w++)h[e.attributes[w].name]=e.attributes[w].value;(s||b)&&(s&&(b&&s.__html==b.__html||s.__html===e.innerHTML)||(e.innerHTML=s&&s.__html||""))}if(de(e,_,h,n,l),s)t.__k=[];else if(me(e,O(w=t.props.children)?w:[w],t,r,o,n&&f!=="foreignObject",a,i,a?a[0]:r.__k&&N(r,0),l,m),a!=null)for(w=a.length;w--;)a[w]!=null&&ce(a[w]);l||("value"in _&&(w=_.value)!==void 0&&(w!==e.value||f==="progress"&&!w||f==="option"&&w!==h.value)&&H(e,"value",w,h.value,!1),"checked"in _&&(w=_.checked)!==void 0&&w!==e.checked&&H(e,"checked",w,h.checked,!1))}return e}function te(e,t,r){try{typeof e=="function"?e(t):e.current=t}catch(o){y.__e(o,r)}}function W(e,t,r){var o,n;if(y.unmount&&y.unmount(e),(o=e.ref)&&(o.current&&o.current!==e.__e||te(o,null,t)),(o=e.__c)!=null){if(o.componentWillUnmount)try{o.componentWillUnmount()}catch(a){y.__e(a,t)}o.base=o.__P=null,e.__c=void 0}if(o=e.__k)for(n=0;n<o.length;n++)o[n]&&W(o[n],t,r||typeof e.type!="function");r||e.__e==null||ce(e.__e),e.__=e.__e=e.__d=void 0}function Le(e,t,r){return this.constructor(e,r)}function Re(e,t,r){var o,n,a,i;y.__&&y.__(e,t),n=(o=typeof r=="function")?null:r&&r.__k||t.__k,a=[],i=[],ee(t,e=(!o&&r||t).__k=ve(j,null,[e]),n||D,D,t.ownerSVGElement!==void 0,!o&&r?[r]:n?null:t.firstChild?F.call(t.childNodes):null,a,!o&&r?r:n?n.__e:t.firstChild,o,i),he(a,e,i)}F=pe.slice,y={__e:function(e,t,r,o){for(var n,a,i;t=t.__;)if((n=t.__c)&&!n.__)try{if((a=n.constructor)&&a.getDerivedStateFromError!=null&&(n.setState(a.getDerivedStateFromError(e)),i=n.__d),n.componentDidCatch!=null&&(n.componentDidCatch(e,o||{}),i=n.__d),i)return n.__E=n}catch(l){e=l}throw e}},ie=0,Y.prototype.setState=function(e,t){var r;r=this.__s!=null&&this.__s!==this.state?this.__s:this.__s=A({},this.state),typeof e=="function"&&(e=e(A({},r),this.props)),e&&A(r,e),e!=null&&this.__v&&(t&&this._sb.push(t),ae(this))},Y.prototype.forceUpdate=function(e){this.__v&&(this.__e=!0,e&&this.__h.push(e),ae(this))},Y.prototype.render=j,T=[],ue=typeof Promise=="function"?Promise.prototype.then.bind(Promise.resolve()):setTimeout,J=function(e,t){return e.__v.__b-t.__v.__b},Z.__r=0;var u=(e=>(e.MOV="MOV",e.PUSH="PUSH",e.POP="POP",e.DB="DB",e.ADDC="ADDC",e.SUBC="SUBC",e.OR="OR",e.XOR="XOR",e.BZS="BZS",e.BZC="BZC",e.RET="RET",e.RETI="RETI",e.CALL="CALL",e.ROTL="ROTL",e.ROTR="ROTR",e.ADC="ADC",e.AND="AND",e.ASL="ASL",e.BBR="BBR",e.BBS="BBS",e.BCC="BCC",e.BCS="BCS",e.BEQ="BEQ",e.BIT="BIT",e.BMI="BMI",e.BNE="BNE",e.BPL="BPL",e.BRA="BRA",e.BRK="BRK",e.BVC="BVC",e.BVS="BVS",e.CLC="CLC",e.CLD="CLD",e.CLI="CLI",e.CLV="CLV",e.CMP="CMP",e.CPX="CPX",e.CPY="CPY",e.DEC="DEC",e.DEX="DEX",e.DEY="DEY",e.EOR="EOR",e.INC="INC",e.INX="INX",e.INY="INY",e.JMP="JMP",e.JSR="JSR",e.LDA="LDA",e.LDX="LDX",e.LDY="LDY",e.LSR="LSR",e.NOP="NOP",e.ORA="ORA",e.PHA="PHA",e.PHP="PHP",e.PHX="PHX",e.PHY="PHY",e.PLA="PLA",e.PLP="PLP",e.PLX="PLX",e.PLY="PLY",e.RMB="RMB",e.ROL="ROL",e.ROR="ROR",e.RTI="RTI",e.RTS="RTS",e.SBC="SBC",e.SEC="SEC",e.SED="SED",e.SEI="SEI",e.SMB="SMB",e.STA="STA",e.STP="STP",e.STX="STX",e.STY="STY",e.STZ="STZ",e.TAX="TAX",e.TAY="TAY",e.TRB="TRB",e.TSB="TSB",e.TSX="TSX",e.TXA="TXA",e.TXS="TXS",e.TYA="TYA",e.WAI="WAI",e))(u||{}),c=(e=>(e.IndexX="X",e.IndexY="Y",e.Accumulator="A",e.StackPointer="S",e.ProgramCounter="R",e.StatusRegister="P",e.ZeroPage="ZP",e))(c||{}),E=(e=>(e.Register="Register",e.OpCode="OpCode",e.Number="Number",e.Pointer="Pointer",e.Label="Label",e.LabelDef="LabelDef",e))(E||{});function $e(e){return e===`
`||e==="\r"}function V(e){var a;let t=0;const r=[],o=new Set;for(;t<e.length;){const i=e[t];switch(i){case" ":case",":case"+":case"	":case"\r":case`
`:t++;continue}if(i===";"){for(;t<e.length&&!$e(e[t]);)t++;continue}if(/[a-zA-Z_]/.test(i)){let h="",_=t;for(;_<e.length&&/[a-zA-Z0-9_]/.test(e[_]);)h+=e[_],_++;if(e[_]===":"){r.push({type:"LabelDef",value:h}),o.add(h),t=_+1;continue}if(o.has(h)){r.push({type:"Label",value:h}),t=_;continue}}const l=[e.slice(t,t+2),e.slice(t,t+3),e.slice(t,t+4)].map(h=>h.toUpperCase()).find(h=>h in u);if(l){r.push({type:"OpCode",value:u[l]}),t+=l.length;continue}const m=[i,e.slice(t,t+2)].map(h=>h.toUpperCase()).find(h=>Object.values(c).indexOf(h)!==-1);if(m){r.push({type:"Register",value:m}),t+=m.length;continue}const d=i+((a=e.at(t+1))==null?void 0:a.toLowerCase());let b,s;switch(d){case"0b":b=/[01]/,s=2;case"0x":b??(b=/[0-9A-Fa-f]/),s??(s=16),t+=2,n(b,s);continue}if(i==="["){const[h,_]=V(e.slice(++t));r.push(...h),t+=_;continue}if(i==="]"){t++;break}if(/[0-9]/.test(i)){n(/[0-9]/,10);continue}throw new TypeError(`Syntax Error: ${i} at ${t}.

    Recent Tokens: ${r.slice(-5).map(h=>h.value).join(" ")}

    Recent String: ${e.slice(t-10,t+10)}`)}return[r,t];function n(i,l){let m="";for(;t<e.length&&i.test(e[t]);)m+=e[t],t++;const d=parseInt(m,l);if(d<=255)r.push({type:"Number",value:d});else if(d<=65535)r.push({type:"Pointer",value:d});else throw new Error(`Number Too Large ${d} raw ${m} at ${t}`)}}var p=(e=>(e.Program="Program",e.CallExpression="CallExpression",e.RegisterLiteral="RegisterLiteral",e.NumberLiteral="NumberLiteral",e.PointerLiteral="PointerLiteral",e.LabelLiteral="LabelLiteral",e))(p||{});function z(e){let t=0;function r(){let n=e[t];if(n.type===E.Number)return t++,{type:"NumberLiteral",value:n.value};if(n.type===E.Pointer)return t++,{type:"PointerLiteral",value:n.value};if(n.type===E.Label)return t++,{type:"LabelLiteral",value:n.value};if(n.type===E.LabelDef)return t++,{type:"LabelLiteral",name:n.value};if(n.type===E.Register){t++;const a={type:"RegisterLiteral",name:n.value,params:[]};switch(a.name){case c.ZeroPage:let i=r();if(i.type!=="NumberLiteral")throw new Error(`ZeroPage must be followed by a number literal, but got ${i.type}`);a.params.push(i),i=r(),i.type==="RegisterLiteral"&&i.name===c.IndexY?a.value=c.IndexY:t--;break}return a}if(n.type===E.OpCode){const a={type:"CallExpression",name:n.value,params:[]};for(n=e[++t];t<e.length&&n.type!==E.OpCode&&n.type!==E.LabelDef;)a.params.push(r()),n=e[t];return a}throw new TypeError(`Unexpected token ${n.type} : ${n.value} at ${t}`)}const o={type:"Program",body:[]};for(;t<e.length;)o.body.push(r());return o}function xe(e,t){function r(n,a){n.forEach(i=>o(i,a))}function o(n,a){const i=t[n.type];switch(i&&i(n,a),n.type){case p.Program:r(n.body,n);break;case p.CallExpression:r(n.params,n);break;case p.RegisterLiteral:case p.NumberLiteral:case p.PointerLiteral:case p.LabelLiteral:break;default:throw new TypeError(`Unexpected node type ${n.type}`)}}o(e)}function Pe(e,t){switch(e.name){case u.NOP:t.value="EA";break;case u.RET:case u.RTS:t.value="60";break;case u.RETI:case u.RTI:t.value="40";break;case u.SEC:t.value="38";break;case u.CLC:t.value="18";break;case u.SEI:t.value="78";break;case u.CLI:t.value="58";break;case u.CLV:t.value="B8";default:throw new Error(`Not Supported opcode: ${e.name} with no params`)}}function Ee(e,t){switch(e.type){case p.NumberLiteral:t.value="90",t.params=[e];break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.BCC}`)}}function Se(e,t){switch(e.type){case p.NumberLiteral:t.value="B0",t.params=[e];break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.BCS}`)}}function Ae(e,t){switch(e.type){case p.NumberLiteral:t.value="D0",t.params=[e];break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.BZC}`)}}function Te(e,t){switch(e.type){case p.NumberLiteral:t.value="F0",t.params=[e];break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.BZS}`)}}function Ue(e,t){switch(e.type){case p.RegisterLiteral:switch(e.name){case c.Accumulator:t.value="3A";break;case c.IndexX:t.value="CA";break;case c.IndexY:t.value="88";break;default:throw new Error(`UnSupport Register: ${e.value} for ${u.DEC}`)}break;case p.PointerLiteral:t.value="CE",t.params=R(e.value);break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.DEC}`)}}function Be(e,t){switch(e.type){case p.RegisterLiteral:switch(e.name){case c.Accumulator:t.value="1A";break;case c.IndexX:t.value="E8";break;case c.IndexY:t.value="C8";break;default:throw new Error(`UnSupport Register: ${e.value} for ${u.INC}`)}break;case p.PointerLiteral:t.value="EE",t.params=R(e.value);break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.INC}`)}}function De(e,t){switch(t.value="4C",e.type){case p.LabelLiteral:t.params=[e];break;case p.PointerLiteral:t.params=R(e.value);break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.JMP}`)}}function Ie(e,t){switch(e.type){case p.PointerLiteral:t.value="20",t.params=R(e.value);break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.JSR}`)}}function Ne(e,t){switch(e.type){case p.RegisterLiteral:switch(e.name){case c.Accumulator:t.value="68";break;case c.IndexX:t.value="FA";break;case c.IndexY:t.value="7A";break;case c.StatusRegister:t.value="28";break;default:throw new Error(`UnSupport Register: ${e.value} for ${u.POP}`)}break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.POP}`)}}function ge(e,t){switch(e.type){case p.RegisterLiteral:switch(e.name){case c.Accumulator:t.value="48";break;case c.IndexX:t.value="DA";break;case c.IndexY:t.value="5A";break;case c.StatusRegister:t.value="08";break;default:throw new Error(`UnSupport Register: ${e.value} for ${u.PUSH}`)}break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.PUSH}`)}}function Xe(e,t){switch(e.type){case p.RegisterLiteral:switch(e.name){case c.Accumulator:t.value="2A";break;default:throw new Error(`UnSupport Register: ${e.value} for ${u.ROL}`)}break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.ROL}`)}}function Ye(e,t){switch(e.type){case p.RegisterLiteral:switch(e.name){case c.Accumulator:t.value="6A";break;default:throw new Error(`UnSupport Register: ${e.value} for ${u.ROR}`)}break;default:throw new Error(`Unexpected param type: ${e.type} for ${u.ROR}`)}}function Ce(e,t){const r=e.params[0];switch(e.name){case u.JMP:De(r,t);break;case u.INC:Be(r,t);break;case u.DEC:Ue(r,t);break;case u.BZS:Te(r,t);break;case u.BZC:Ae(r,t);break;case u.BCS:Se(r,t);break;case u.BCC:Ee(r,t);break;case u.PUSH:ge(r,t);break;case u.POP:Ne(r,t);break;case u.CALL:case u.JSR:Ie(r,t);break;case u.ROTL:case u.ROL:Xe(r,t);break;case u.ROTR:case u.ROR:Ye(r,t);break;default:throw new Error(`UnSupport OpCode: ${e.name} with 1 param`)}}function Me(e,t,r){switch(t.type){case p.RegisterLiteral:switch(t.name){case c.Accumulator:switch(r.type){case p.NumberLiteral:e.value="69",e.params=[r];break;case p.PointerLiteral:e.value="6D",e.params=R(r.value);break;case p.RegisterLiteral:switch(r.name){case c.ZeroPage:r.value===c.IndexY?e.value="71":e.value="72",e.params=r.params;break;default:throw new Error(`Unsupport Right Register: ${r.name} for ${e.name}`)}break;default:throw new Error(`Unsupport Right param type: ${r.type} for ${e.name}`)}break;default:throw new Error(`Unsupport Left Register: ${t.name} for ${e.name}`)}break;default:throw new Error(`Unexpected Left param type: ${t.type} for ${e.name}`)}}function Ze(e,t,r){switch(t.type){case p.RegisterLiteral:switch(t.name){case c.Accumulator:switch(r.type){case p.NumberLiteral:e.value="29",e.params=[r];break;case p.PointerLiteral:e.value="2D",e.params=R(r.value);break;case p.RegisterLiteral:switch(r.name){case c.ZeroPage:r.value===c.IndexY?e.value="31":e.value="32",e.params=r.params;break;default:throw new Error(`Unsupport Right Register: ${r.name} for ${e.name}`)}break;default:throw new Error(`Unsupport Right param type: ${r.type} for ${e.name}`)}break;default:throw new Error(`Unsupport Left Register: ${t.name} for ${e.name}`)}break;default:throw new Error(`Unexpected Left param type: ${t.type} for ${e.name}`)}}function He(e,t,r){switch(e.type){case p.RegisterLiteral:switch(e.name){case c.Accumulator:switch(t.type){case p.NumberLiteral:r.value="C9",r.params=[t];break;case p.PointerLiteral:r.value="CD",r.params=R(t.value);break;case p.RegisterLiteral:switch(t.name){case c.ZeroPage:t.value===c.IndexY?r.value="D1":r.value="D2",r.params=t.params;break;default:throw new Error(`Unsupport Right Register: ${t.name} for ${r.name}`)}break;default:throw new Error(`Unsupport Right param type: ${t.type} for ${r.name}`)}break;case c.IndexX:switch(t.type){case p.NumberLiteral:r.value="E0",r.params=[t];break;case p.PointerLiteral:r.value="EC",r.params=R(t.value);break;default:throw new Error(`Unsupport Right param type: ${t.type} for ${r.name}`)}break;case c.IndexY:switch(t.type){case p.NumberLiteral:r.value="C0",r.params=[t];break;case p.PointerLiteral:r.value="CC",r.params=R(t.value);break;default:throw new Error(`Unsupport Right param type: ${t.type} for ${r.name}`)}break;default:throw new Error(`Unsupport Left Register: ${e.name} for ${r.name}`)}break;default:throw new Error(`Unexpected Left param type: ${e.type} for ${r.name}`)}}function Ve(e,t,r){switch(t.type){case p.RegisterLiteral:switch(t.name){case c.Accumulator:switch(r.type){case p.NumberLiteral:e.value="49",e.params=[r];break;case p.PointerLiteral:e.value="4D",e.params=R(r.value);break;case p.RegisterLiteral:switch(r.name){case c.ZeroPage:r.value===c.IndexY?e.value="51":e.value="52",e.params=r.params;break;default:throw new Error(`Unsupport Right Register: ${r.name} for ${e.name}`)}break;default:throw new Error(`Unsupport Right param type: ${r.type} for ${e.name}`)}break;default:throw new Error(`Unsupport Left Register: ${t.name} for ${e.name}`)}break;default:throw new Error(`Unexpected Left param type: ${t.type} for ${e.name}`)}}function Fe(e,t,r){switch(t.type){case p.RegisterLiteral:switch(r.params=R(e.value),t.name){case c.Accumulator:r.name=u.STA,r.value="8D";break;case c.IndexX:r.name=u.STX,r.value="8E";break;case c.IndexY:r.name=u.STY,r.value="8C";break;default:throw new Error(`Unsupport Right Register: ${t.value} for ${r.name}`)}break;default:throw new Error(`Unsupport Right param type: ${t.type} for ${r.name}`)}}function je(e,t,r){switch(e.name){case c.Accumulator:switch(t.name){case c.IndexX:r.name=u.TXA,r.value="8A";break;case c.IndexY:r.name=u.TYA,r.value="98";break;case c.ZeroPage:r.name=u.LDA,t.value===c.IndexY?r.value="B1":r.value="B2",r.params=t.params;break;default:throw new Error(`Unsupport Register Pair: ${e.name} : ${t.name} for ${r.name}`)}break;case c.IndexX:switch(t.name){case c.Accumulator:r.name=u.TAX,r.value="AA";break;case c.StackPointer:r.name=u.TSX,r.value="BA";break;default:throw new Error(`Unsupport Register Pair: ${e.name} : ${t.name} for ${r.name}`)}break;case c.IndexY:switch(t.name){case c.Accumulator:r.name=u.TAY,r.value="A8";break;default:throw new Error(`Unsupport Register Pair: ${e.name} : ${t.name} for ${r.name}`)}break;case c.StackPointer:switch(t.name){case c.IndexX:r.name=u.TXS,r.value="9A";break;default:throw new Error(`Unsupport Register Pair: ${e.name} : ${t.name} for ${r.name}`)}break;case c.ZeroPage:switch(t.name){case c.Accumulator:r.name=u.STA,e.value===c.IndexY?r.value="91":r.value="92",r.params=e.params;break;default:throw new Error(`Unsupport Register Pair: ${e.name} : ${t.name} for ${r.name}`)}break;default:throw new Error(`Unsupport Left Register: ${e.name} for ${r.name}`)}}function Je(e,t,r){switch(e.name){case c.Accumulator:switch(r.name=u.LDA,t.type){case p.NumberLiteral:r.value="A9",r.params=[t];break;case p.PointerLiteral:r.value="AD",r.params=R(t.value);break;default:throw new Error(`Unsupport Right param type: ${t.type} for ${r.name}`)}break;case c.IndexX:switch(r.name=u.LDX,t.type){case p.NumberLiteral:r.value="A2",r.params=[t];break;case p.PointerLiteral:r.value="AE",r.params=R(t.value);break;default:throw new Error(`Unsupport Right param type: ${t.type} for ${r.name}`)}break;case c.IndexY:switch(r.name=u.LDY,t.type){case p.NumberLiteral:r.value="A0",r.params=[t];break;case p.PointerLiteral:r.value="AC",r.params=R(t.value);break;default:throw new Error(`Unsupport Right param type: ${t.type} for ${r.name}`)}break;default:throw new Error(`Unsupport Left Register: ${e.name} for ${r.name}`)}}function We(e,t,r){switch(e.type){case p.RegisterLiteral:if(t.type===p.RegisterLiteral){je(e,t,r);break}Je(e,t,r);break;case p.PointerLiteral:Fe(e,t,r);break;default:throw new Error(`Unexpected Left param type: ${e.type} for ${r.name}`)}}function ze(e,t,r){switch(t.type){case p.RegisterLiteral:switch(t.name){case c.Accumulator:switch(r.type){case p.NumberLiteral:e.value="09",e.params=[r];break;case p.PointerLiteral:e.value="0D",e.params=R(r.value);break;case p.RegisterLiteral:switch(r.name){case c.ZeroPage:r.value===c.IndexY?e.value="11":e.value="12",e.params=r.params;break;default:throw new Error(`Unsupport Right Register: ${r.name} for ${e.name}`)}break;default:throw new Error(`Unsupport Right param type: ${r.type} for ${e.name}`)}break;default:throw new Error(`Unsupport Left Register: ${t.name} for ${e.name}`)}break;default:throw new Error(`Unexpected Left param type: ${t.type} for ${e.name}`)}}function Ge(e,t,r){switch(t.type){case p.RegisterLiteral:switch(t.name){case c.Accumulator:switch(r.type){case p.NumberLiteral:e.value="E9",e.params=[r];break;case p.PointerLiteral:e.value="ED",e.params=R(r.value);break;case p.RegisterLiteral:switch(r.name){case c.ZeroPage:r.value===c.IndexY?e.value="F1":e.value="F2",e.params=r.params;break;default:throw new Error(`Unsupport Right Register: ${r.name} for ${e.name}`)}break;default:throw new Error(`Unsupport Right param type: ${r.type} for ${e.name}`)}break;default:throw new Error(`Unsupport Left Register: ${t.name} for ${e.name}`)}break;default:throw new Error(`Unexpected Left param type: ${t.type} for ${e.name}`)}}function Ke(e,t){const r=e.params[0],o=e.params[1];switch(e.name){case u.MOV:We(r,o,t);break;case u.ADDC:case u.ADC:Me(t,r,o);break;case u.SUBC:case u.SBC:Ge(t,r,o);break;case u.AND:Ze(t,r,o);break;case u.OR:case u.ORA:ze(t,r,o);break;case u.XOR:case u.EOR:Ve(t,r,o);break;case u.CMP:He(r,o,t);break;default:throw new Error(`UnSupport OpCode: ${e.name} with 2 params`)}}function we(e){const t=e.toString(16).padStart(4,"0");return[t.slice(2,4),t.slice(0,2)]}function R(e){return we(e).map(t=>({type:p.NumberLiteral,value:t}))}function G(e){const t={type:p.Program,body:[]};return e.context=t.body,xe(e,{[p.LabelLiteral](r,o){(o==null?void 0:o.type)===p.Program&&t.body.push(r)},[p.CallExpression](r,o){var a,i;const n={type:p.CallExpression,name:r.name,params:[]};if(n.name===u.DB)n.params=r.params;else switch((a=r.params)==null?void 0:a.length){case 1:Ce(r,n);break;case 2:Ke(r,n);break;case 0:case void 0:Pe(r,n);break;default:throw new Error(`Params length out of range: ${(i=r.params)==null?void 0:i.length} for opcode: ${r.name}`)}o.context.push(n)}}),t}let C=0;const K=new Map;function q(e){return C=0,K.clear(),M(e)}function M(e){switch(e.type){case p.Program:return e.body.map(M).join(`
`);case p.LabelLiteral:return e.name?(K.set(e.name,C),""):we(K.get(e.value)).join(" ");case p.CallExpression:return e.name===u.DB?e.params.map(M).join(" "):(C++,`${e.value} ${e.params.map(M).join(" ")}`);case p.NumberLiteral:return C++,e.value.toString(16).padStart(2,"0").toUpperCase();default:throw new Error(`Unknown AST type: ${e.type}`)}}function qe(e){return q(G(z(V(e)[0])))}const Qe="/assets/preact-48177e6f.svg";const Oe=`
;loading something into a register:
mov a, 0x55
mov a, [ 0x1234 ]
mov x, 0x55
mov x, [ 0x1234 ]
mov y, 0x55
mov y, [ 0x1234 ]
; storing the value from a register into memory:
mov [ 0x1234 ], a
mov [ 0x1234 ], x
mov [ 0x1234 ], y
; moving between registers:
mov a, x
mov x, a
mov a, y
mov y, a
;arithmetic and logic operations, the result always goes to A
addc a, 0x55	; adds two bytes
addc a, [ 0x1234 ]
subc a, 0x55	; substract
subc a, [ 0x1234 ]
and a, 0x55	; biwise and
and a, [ 0x1234 ]
or a, 0x55	; bitwise or
or a, [ 0x1234 ]
xor a, 0x55	; bitwise xor
xor a, [ 0x1234 ]
inc a	; increment (add one)
inc x
inc y
inc [ 0x1234 ]
dec a	; decrement (substract one)
dec x
dec y
dec [ 0x1234 ]
; comparison operations (more explanations in the next class)
cmp a, 0x55
cmp a, [ 0x1234 ]
cmp x, 0x55
cmp x, [ 0x1234 ]
cmp y, 0x55
cmp y, [ 0x1234 ]
; conditional jump. The meaning of the immediate value
; will be explaine in the next class, or you can read the datasheet
bzs 0x55
bzc 0x55
bcs 0x55

start:
jmp start
mov a, 0x11
mov [0x3000], x
mov y, 0x21
inc x
addc a, 0x02
`;var et=0;function Q(e,t,r,o,n,a){var i,l,m={};for(l in t)l=="ref"?i=t[l]:m[l]=t[l];var d={type:e,props:m,key:r,ref:i,__k:null,__:null,__b:0,__e:null,__d:void 0,__c:null,__h:null,constructor:void 0,__v:--et,__source:n,__self:a};if(typeof e=="function"&&(i=e.defaultProps))for(l in i)m[l]===void 0&&(m[l]=i[l]);return y.vnode&&y.vnode(d),d}function tt(){window.TestASM=Oe,window.Tokenizer=V,window.Parser=z,window.Transformer=G,window.Generator=q,window.Assembler=qe;const e=V("hellostring:   db 72, 101, 108, 108, 111, 0");console.log(e);const t=z(e[0]);console.log(t);const r=G(t),o=q(r);return console.log(o),Q("div",{children:Q("img",{src:Qe})})}Re(Q(tt,{}),document.getElementById("app"));